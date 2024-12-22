/** Add 3.
 * This program adds two strings and moves the cursor to a hardcoded location. */

#include <stdlib.h>
#include <ncurses.h>

// TODO: Figure out how to report errors.
void AddStr(const char* str) {
  if (addstr(str) == ERR) {
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char* argv[argc]) {
  char* t1 = "The first sentence\n";
  char* t2 = "The second sentence";

  initscr();

  AddStr(t1);
  AddStr(t2);

  // This moves to row 3, column 1 relative to the origin (0,0)
  move(2, 0);

  AddStr("Now the cursor is somewhere else");

  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
