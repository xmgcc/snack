#include <curses.h>
#include <stdlib.h>
#include "linklist2.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 20


// 全局变量, g_前缀定义变量
// 一级指针  *
struct Snack *g_snack;



//////////////////////////////////////////


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
                    if (linklist_find(g_snack, x, y) == 0)
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


/* void init_map2() */
/* { */
/*     int x; */
/*     int y; */
/*  */
/*     for (x = 0; x < MAP_HEIGHT; x++) */
/*     { */
/*         for (y = 0; y < MAP_WIDTH; y++) */
/*         { */
/*             if (x == 0 || x == 19) */
/*             { */
/*                 // red */
/*                 printw("##"); */
/*             } */
/*             else  */
/*             { */
/*                 // green */
/*                 if (y == 0 || y == 19) */
/*                 { */
/*                     if (y == 0) */
/*                     { */
/*                         printw("# "); */
/*                     } */
/*                     else */
/*                     { */
/*                         printw(" #"); */
/*                     } */
/*                 } */
/*                 else */
/*                 { */
/*                     printw("  "); */
/*                 } */
/*             } */
/*         } */
/*         printw("\n"); */
/*     } */
/* } */
/*      */
/* void init_map() */
/* { */
/*     int x; */
/*     int y; */
/*     // print */
/*     for (x = 0; x < MAP_WIDTH; x++) */
/*     { */
/*         for (y = 0; y < MAP_HEIGHT; y++) */
/*         { */
/*             // 0 || 19 */
/*             if (y == 0 || y == MAP_HEIGHT - 1) */
/*             { */
/*                 if (y == 0) */
/*                 { */
/*                     printw("# "); */
/*                 } */
/*                 else */
/*                 { */
/*                     printw(" #"); */
/*                 } */
/*             } */
/*             else */
/*             { */
/*                 // 0 || 19 */
/*                 if (x == 0 || x == MAP_WIDTH -1) */
/*                 { */
/*                     printw("##"); */
/*                 } */
/*                 else */
/*                 { */
/*                     printw("  "); */
/*                 } */
/*             } */
/*         } */
/*         printw("\n"); */
/*     } */
/* } */
/*  */
void create_snack()
{
    g_snack = (struct Snack*)malloc(sizeof(struct Snack));
    g_snack->x = 3;
    g_snack->y = 3;
    g_snack->next = NULL;

    // 改变一个变量的值要传地址
    // g_snack 一级指针
    // &g_snack 2级指针
    linklist_insert(&g_snack, 3, 4);
    g_snack = linklist_insert2(g_snack, 3, 5);

}

// CTRL + C
void handle_keys()
{
    int key;

    noecho();

    keypad(stdscr, TRUE);
    while(1)
    {
        // wait key
        key = getch();
        switch(key) {
            case KEY_DOWN:
                break;
            case KEY_UP:
                break;
            case KEY_LEFT:
                break;
            case KEY_RIGHT:
                // 清屏，光标复位
                clear();

                linklist_insert(&g_snack, g_snack->x, g_snack->y + 1);
                linklist_delete(g_snack);
                init_map3();
                break;
            default:
                break;
        }
    }
}

int main()
{
    // init
    initscr();

    // 创建贪吃蛇
    create_snack();

    // 创建地图
    init_map3();

    handle_keys();

    // destroy
    endwin();
    return 0;
}
