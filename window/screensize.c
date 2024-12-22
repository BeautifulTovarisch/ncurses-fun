/** Screensize
 * Measures and outputs the size of the curses window. */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();

  // Measure the maximum width and height of the default 'stdscr'.
  int y,x;
  getmaxyx(stdscr, y, x);
  printw("height: %d, width: %d\n", y, x);
  // The constants LINES and COLS are equivalent to these values.
  printw("LINES: %d, COLS: %d\n", LINES, COLS);
  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
