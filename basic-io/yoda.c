/** Yoda
 * This program demonstrates ncurse's printw function which formats text before
 * writing it to the window. There is some kind of pun about Star Wars which is
 * lost on me. */

#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char* argv[argc]) {
  int yoda = 874;
  int ssn = 65;

  initscr();

  printw("Yoda is %d years old\n", yoda);
  printw("SSN: %d", ssn);

  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
