/** Marquee
 * This program uses the insch() function to simulate the effect of scrolling
 * text on a marquee */

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

// Populate the with the alphabet
void fill(void) {
  int y, x;
  getmaxyx(stdscr, y, x);

  for (size_t i = 0; i < y; i++) {
    addstr("* * * * * * * * * * * * * * * * * * * * * * * * * *\n");
  }

  refresh();
}

int main(int argc, char* argv[argc]) {
  char* text = "I am the marquee text!";

  initscr();
  fill();

  size_t len = strlen(text);
  // Start from the end of the string
  for (char* t = text + (len-1); *t; t--) {
    move(5, 5);
    insch(*t);
    refresh();
    napms(100);
  }

  getch();
  endwin();

  return EXIT_SUCCESS;
}
