// 撞墙游戏结束
//
#include <curses.h>
#include "linklist.h"
// 全局变量用g_开头
struct SnackLinkList *g_snack = NULL;
int g_head_x = 0;
int g_head_y = 0;

#define MAP_WIDTH 20
#define MAP_HEIGHT 20


void redraw_map();
void create_snack();
void destroy_snack();

void game_over()
{
    clear();

    printw("-------------------\n");
    printw("       GAME OVER\n");
    printw("-------------------\n");

    destroy_snack();
    create_snack();

    // 按任意键继续
    getch();
}

void process_key()
{
    int key;
    key = getch();
    switch (key) {
        case KEY_UP:
            g_head_x--;
            break;
        case KEY_DOWN:
            g_head_x++;
            break;
        case KEY_LEFT:
            g_head_y--;
            break;
        case KEY_RIGHT:
            g_head_y++;
            break;
        default:
            // 打印其他按键
            printw("   0%o, %c\n", key, key);
            return;
    }

    if (g_head_x <= 0 || g_head_x >= MAP_WIDTH ||
        g_head_y <= 0 || g_head_y >= MAP_HEIGHT)
    {
        game_over();
    } else {
        linklist_insert(&g_snack, g_head_x, g_head_y);
        linklist_delete_tail(g_snack);
    }
}

void init_ncurse()
{
    // 不显示输入的按键
    noecho();

    // Special keys. In order to capture special keystrokes like Backspace,
    // Delete and the four arrow keys by getch(), you need to call
    keypad(stdscr, TRUE);
}

void redraw_map()
{
    int x;
    int y;

    // 清屏,光标复位
    clear();

    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            if (x == 0 || x == MAP_WIDTH - 1) {
                printw("--");
            } else if (y == 0 || y == MAP_HEIGHT - 1) {
                if (y == 0) {
                    printw("| ");
                } else {
                    printw(" |");
                }
            } else {
                // 打印蛇的身子或者空格
                if (linklist_find(g_snack, x, y) == 0) {
                    printw("[]");
                } else {
                    printw("  ");
                }
            }
        }
        printw("\n");
    }
}


void create_snack()
{
    g_snack = linklist_create(1, 1, 3);
    g_head_x = 1;
    g_head_y = 3;
}

void destroy_snack()
{
    while(linklist_delete_tail(g_snack) == 0) {
    }
}

int main()
{
    initscr();

    init_ncurse();

    create_snack();

    redraw_map();

    while (1) {
        process_key();
        redraw_map();
    }

    endwin();
}
