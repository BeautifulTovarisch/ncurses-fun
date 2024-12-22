/** Corners *
 * This program move the cursor to each of the corners of the window */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {

  initscr();
  // Measure screen
  int rows, cols;
  getmaxyx(stdscr, rows, cols);

  // Offset by one for convenience
  rows--;
  cols--;

  // Move the cursor to each corner and add a single character.
  // The cursor begins at the origin, so the first move() is superfluous.

  // Origin
  move(0, 0);
  addch('*');
  refresh();
  napms(500);

  // Top right
  move(0, cols);
  addch('*');
  refresh();
  napms(500);

  // Bottom Right
  move(rows, cols);
  addch('*');
  refresh();
  napms(500);

  // Bottom Left
  move(rows, 0);
  addch('*');
  refresh();
  napms(500);

  getch();
  endwin();

  return EXIT_SUCCESS;
}
