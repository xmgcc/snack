#include <curses.h>


#define MAP_WIDTH 20
#define MAP_HEIGHT 20


struct Snack {
    // x坐标
    int x;
    // y坐标
    int y;
};

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
                    if (x == g_snack.x && y == g_snack.y)
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

int main()
{
    // init
    initscr();

    g_snack.x = 3;
    g_snack.y = 3;
    
    init_map3();

    // wait key
    getch();
    
    // destroy
    endwin();
    return 0;
}
