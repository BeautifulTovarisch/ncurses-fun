/** Flush
 * This program flushes the keyboard buffer to avoid inadvertently processing
 * characters */

#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();

  addstr("Enter some text in the keyboard: \n");
  refresh();
  napms(5000);

  addstr("Here's what you typed:\n");
  flushinp();

  // Read at most 80 characters from the keyboard buffer. This is empty due to
  // the call to flushinp()
  char buf[81];
  getnstr(buf, 80);
  refresh();

  endwin();

  return EXIT_SUCCESS;
}
