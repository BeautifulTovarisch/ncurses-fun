/** Two Windows
 * This program creates a new window alongside the standard ncurses window. */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();

  addstr("Original window \n");
  refresh();
  getch();

  // rows, cols, (y, x)
  WINDOW* two = newwin(0, 0, 0, 0);
  if (!two) {
    addstr("unable to create new window. Exiting...");
    endwin();

    return EXIT_FAILURE;
  }

  waddstr(two, "This should appear on the second window\n");
  wrefresh(two);

  getch();
  endwin();

  return EXIT_SUCCESS;
}
