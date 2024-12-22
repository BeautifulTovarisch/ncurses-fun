/** Hamlet
 * This program prints an excerpt from Hamlet in order to demonstrate inserting
 * lines */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  char *h1 = "To be, or not to be: that is the question:\n";
  char *h2 = "Whether 'tis nobler in the mind to suffer\n";
  char *h3 = "The slings and arrows of outrageous fortune,\n";
  char *h4 = "Or to take arms against a sea of troubles,\n";
  char *h5 = "And by opposing end them?\n";

  initscr();

  addstr(h1);
  addstr(h3);
  addstr(h5);
  refresh();
  getch();

  // Move to the second line and insert a blank string
  move(1, 0);
  insertln();
  addstr(h2);
  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
