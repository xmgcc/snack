// 识别上下左右按键
#include <curses.h>
int main()
{
    int key;  // getch()返回类型是int
    initscr();

    // 不显示输入的按键
    noecho();

    // Special keys. In order to capture special keystrokes like Backspace,
    // Delete and the four arrow keys by getch(), you need to call
    keypad(stdscr, TRUE);

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
    endwin();
}
