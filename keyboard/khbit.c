/** KHBIT
 * khbit() is apparently a DOS function that determined whether characters were
 * waiting to be read from a keyboard buffer. This can be emulated with nodelay,
 * getch(), and ungetch() */

#include <stdlib.h>
#include <ncurses.h>

// khbit() tests if input is buffered by taking advantage of getch()'s behavior
// when nodelay=TRUE.
bool khbit() {
  nodelay(stdscr, TRUE);
  noecho();

  // getch() returns an ERR if no character is buffered.
  char ch = getch();
  bool waiting = (ch != ERR);

  // Put the character back on the buffer if there was one.
  if (waiting) {
    ungetch(ch);
  }

  echo();
  nodelay(stdscr, FALSE);

  return waiting;
}

int main(int argc, char* argv[argc]) {
  initscr();

  // TODO: Refresh is not needed here. Need to understand why.
  addstr("Press any key to terminate:");

  while (!khbit());

  endwin();

  return EXIT_SUCCESS;
}
