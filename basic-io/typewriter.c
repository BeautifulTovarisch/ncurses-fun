/** Typewriter
 * This p\nrogram reads and writes out a single character of input at a time. It
 * also demonstrates the first program to exit on a specific user input. */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  char* welcome = "Typewriter:\nType a few lines of text:\n";
  char* quit = "Press '~' to exit\n";

  initscr();
  if (addstr(welcome) == ERR)
    exit(EXIT_FAILURE);

  if (addstr(quit) == ERR)
    exit(EXIT_FAILURE);

  char ch;
  // getch automatically refreshes the window. No need to call refresh()
  while ((ch = getch()) != '~');

  endwin();

  return EXIT_SUCCESS;
}
