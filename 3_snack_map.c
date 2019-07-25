// 地图
//
#include <curses.h>

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
    int i;
    int j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (i == 0 || i == 19) {
                printw("--");
            } else if (j == 0 || j == 19) {
                if (j == 0) {
                    printw("| ");
                } else {
                    printw(" |");
                }
            } else {
                printw("  ");
            }
        }
        printw("\n");
    }
}

int main()
{
    initscr();

    init_map();

    getch();

    endwin();
}
