// ncurses的hello world
#include <curses.h>
int main()
{
    initscr();
    printw("hello\n");
    getch();
    endwin();
}
