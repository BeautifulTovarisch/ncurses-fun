/** Corners 2
 * This program has identical output to Corners 1, but condenses the invocations
 * of move() and addch() into mvaddch() */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();
  int rows, cols;
  getmaxyx(stdscr, rows, cols);

  rows--;
  cols--;

  // The same operations, condensed into a single function call
  mvaddch(0, 0, '*');
  refresh();
  napms(500);

  mvaddch(0, cols, '*');
  refresh();
  napms(500);

  mvaddch(rows, cols, '*');
  refresh();
  napms(500);

  mvaddch(rows, 0, '*');
  refresh();
  napms(500);

  getch();
  endwin();

  return EXIT_SUCCESS;
}
