/** Clear
 * This program performs a single call to refresh(). This has the effect of
 * clearing the curses screen. */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();
  refresh();

  endwin();

  return EXIT_SUCCESS;
}
