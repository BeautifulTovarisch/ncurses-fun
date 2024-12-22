/** Goodbye
 * This program outputs a string to the terminal. It serves as a basic ncurses
 * program. */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();

  addstr("Goodbye!");
  refresh();

  // Wait for user input before closing.
  getch();

  endwin();

  return EXIT_SUCCESS;
}
