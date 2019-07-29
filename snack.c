#include <curses.h>
#include <stdlib.h>


#define MAP_WIDTH 20
#define MAP_HEIGHT 20

//
// 链表操作
//

struct Snack {
    // x坐标
    int x;

    // y坐标
    int y;

    // 单链表节点
    struct Snack *next;
};


// 链表遍历
// 空实现
// 污染,不可重入
// x坐标
// y坐标
// 0表示找到节点，-1表示没找到对应的节点
int linklist_find(struct Snack *head, int x, int y)
{
    struct Snack *p;

    p = head;
    while(p != NULL)
    {
        // 找到节点
        if (p->x ==x && p->y == y)
        {
            return 0;
        }

        p = p->next;
    }

    return -1;
}

//////////////////////////////////////////


// 全局变量, g_前缀定义变量
struct Snack g_snack;

void init_map3()
{
    // 局部变量
    int x;
    int y;

    // 打印行
    for (x = 0; x < MAP_HEIGHT; x++)
    {
        // 打印列
        for (y = 0; y < MAP_WIDTH; y++)
        {
            if(x == 0 || x == MAP_HEIGHT -1)
            {
                // 如果第一行或者最后一行 ,0, 19
                printw("--");
            }
            else
            {
                // [1,18]

                if (y == 0 || y == MAP_WIDTH - 1)
                {
                    // 第1列或第19列
                    if (y == 0)
                    {
                        printw("| ");
                    }
                    else
                    {
                        printw(" |");
                    }
                }
                else
                {
                    // 2,3,4,5...18
                    // 遇到蛇的节点就打印[]，否则打印空格
                    //if (x == g_snack.x && y == g_snack.y)
                    if (linklist_find(&g_snack, x, y) == 0)
                    {
                        printw("[]");
                    }
                    else
                    {
                        printw("  ");
                    }
                }
            }
        }
        printw("\n");
    }
}


void init_map2()
{
    int x;
    int y;

    for (x = 0; x < MAP_HEIGHT; x++)
    {
        for (y = 0; y < MAP_WIDTH; y++)
        {
            if (x == 0 || x == 19)
            {
                // red
                printw("##");
            }
            else 
            {
                // green
                if (y == 0 || y == 19)
                {
                    if (y == 0)
                    {
                        printw("# ");
                    }
                    else
                    {
                        printw(" #");
                    }
                }
                else
                {
                    printw("  ");
                }
            }
        }
        printw("\n");
    }
}
    
void init_map()
{
    int x;
    int y;
    // print
    for (x = 0; x < MAP_WIDTH; x++)
    {
        for (y = 0; y < MAP_HEIGHT; y++)
        {
            // 0 || 19
            if (y == 0 || y == MAP_HEIGHT - 1)
            {
                if (y == 0)
                {
                    printw("# ");
                }
                else
                {
                    printw(" #");
                }
            }
            else
            {
                // 0 || 19
                if (x == 0 || x == MAP_WIDTH -1)
                {
                    printw("##");
                }
                else
                {
                    printw("  ");
                }
            }
        }
        printw("\n");
    }
}

void create_snack()
{
    g_snack.x = 3;
    g_snack.y = 3;
    g_snack.next = NULL;

    struct Snack *node = (struct Snack*)malloc(sizeof(struct Snack));
    node->x = 3;
    node->y = 4;
    node->next = NULL;

    g_snack.next=node;
}

int main()
{
    // init
    initscr();

    // 创建贪吃蛇
    create_snack();

    // 创建地图
    init_map3();

    // wait key
    getch();
    
    // destroy
    endwin();
    return 0;
}
