/** Erase
 * This program fills the screen with junk in order to demonstrate ncurses's
 * functions for erasing text */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char *argv[argc]) {
  initscr();

  int rows, cols;
  getmaxyx(stdscr, rows, cols);

  // Dividing by 5 in order to distribute the 5 characters of "text " evenly.
  for(size_t i = 0; i < (rows*cols) / 5; i++) {
    addstr("text ");
  }

  refresh();
  getch();

  // Clear line 5 starting at column 20
  move(5, 20);
  clrtoeol();
  refresh();
  getch();

  // Then clear to the bottom of the screen
  clrtobot();
  refresh();
  getch();

  // Completely clear the screen
  clear();
  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
