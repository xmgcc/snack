// 上下左右
//
#include <curses.h>
#include "linklist.h"
// 全局变量用g_开头
struct SnackLinkList *g_snack = NULL;
int g_head_x = 0;
int g_head_y = 0;


void redraw_map();

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

    linklist_insert(&g_snack, g_head_x, g_head_y);
    linklist_delete_tail(g_snack);
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

    for (x = 0; x < 20; x++) {
        for (y = 0; y < 20; y++) {
            if (x == 0 || x == 19) {
                printw("--");
            } else if (y == 0 || y == 19) {
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

int main()
{
    initscr();

    init_ncurse();

    g_snack = linklist_create(1, 1, 3);
    g_head_x = 1;
    g_head_y = 3;

    redraw_map();

    while (1) {
        process_key();
        redraw_map();
    }

    endwin();
}
