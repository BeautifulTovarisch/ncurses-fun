/** Add 2
 * This program improves upon the previous by using the addstr() function to add
 * an entire string to the window rather than loop through each character. */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  char* t1 = "I am the first string\n";
  char* t2 = "and I am the second";

  initscr();

  if (addstr(t1) == ERR) {
    exit(EXIT_FAILURE);
  }

  if (addstr(t2) == ERR) {
    exit(EXIT_FAILURE);
  }

  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
