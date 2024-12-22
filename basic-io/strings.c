/** Strings
 * This program reads and outputs strings. The more secure getnstr() function is
 * used to prevent buffer overflow. */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  char first[4];
  char last[4];

  initscr();

  addstr("Enter the first 3 characters of your first name: ");
  refresh();
  getnstr(first, 3);

  addstr("Enter the first 3 characters of your last name: ");
  refresh();
  getnstr(last, 3);

  printw("You entered: %s,%s\n", first, last);
  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
