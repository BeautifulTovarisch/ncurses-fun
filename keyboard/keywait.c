/** Key Wait
 * This program demonstrates the various behaviors of getch() */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();

  // This shows the blocking behavior of getch().
  addstr("Press any key to begin:\n");
  refresh();
  getch();

  // Setting nodelay on the screen will cause getch() to be non-blocking.
  nodelay(stdscr, TRUE);
  refresh();
  addstr("Press any SPACEBAR to stop:\n");

  // NOTE: This will overflow if the program is not terminated.
  int value = 0;
  while (getch() != ' ') {
    printw("value: %d\r", value++);
    refresh();
  }

  int y,x;
  getyx(stdscr, y, x);

  mvaddstr(y+1, x, "Done!");

  nodelay(stdscr, FALSE);
  getch();
  endwin();

  return EXIT_SUCCESS;
}
