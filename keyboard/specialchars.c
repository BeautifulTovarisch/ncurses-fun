/** Special Characters
 * Demonstrates how to read 'special characters' from the keyboard. Ncurses
 * enumerates the keys on a keyboard for portability. */

// TODO: Find a convenient table of these.

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();

  // The keypad function activates ncurse's enumeration (I think?)
  keypad(stdscr, TRUE);

  int ch;
  noecho();
  while (ch != '\n') {
    ch = getch();
    switch(ch) {
      case KEY_UP:
        addstr("UP\n");
        break;
      case KEY_RIGHT:
        addstr("RIGHT\n");
        break;
      case KEY_DOWN:
        addstr("Down\n");
        break;
      case KEY_LEFT:
        addstr("LEFT\n");
        break;
    }

    refresh();
  }

  endwin();

  return EXIT_SUCCESS;
}
