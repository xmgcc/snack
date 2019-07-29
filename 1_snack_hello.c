// ncurses的hello world
#include <curses.h>
int main()
{
    // init
    initscr();

    // printf
    printw("hello\n");

    // 
    getch();

    // destroy
    endwin();
    return 0;
}
