/** Add 1
 * This program draws a string to the terminal one character at a time. A slight
 * delay between each character is added for visual effect. */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  char* text = "Greetings from NCurses!";

  initscr();

  for (char* t = text; *t; t++) {
    if (addch(*t) == ERR) {
      // What do we do here? Exit?
      exit(EXIT_FAILURE);
    }

    refresh();
    napms(100);
  }

  getch();
  endwin();

  return EXIT_SUCCESS;
}
