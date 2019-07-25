// 地图上显示蛇的身子
//
#include <curses.h>
#include "linklist.h"
// 全局变量用g_开头
struct SnackLinkList g_snack = {-1, 3, 3, NULL};

void process_key()
{
    int key;
    while (1) {
        key = getch();
        switch (key) {
            case KEY_UP:
                printw("KEY_UP\n");
                break;
            case KEY_DOWN:
                printw("KEY_DOWN\n");
                break;
            case KEY_LEFT:
                printw("KEY_LEFT\n");
                break;
            case KEY_RIGHT:
                printw("KEY_RIGHT\n");
                break;
            default:
                // 打印其他按键
                printw("   0%o, %c\n", key, key);
                break;
        }
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

void init_map()
{
    int x;
    int y;
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
                if (linklist_find(&g_snack, x, y) == 0) {
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
    struct SnackLinkList node = {0, 3, 2, NULL};
    g_snack.next = &node;

    init_map();

    getch();

    endwin();
}
