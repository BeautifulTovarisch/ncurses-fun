/** Where Am I?
 * This program outputs the position of the cursor as input is read. This shows
 * how the current position of the cursor can be obtained with getyx(). After
 * each keystroke, the position of the cursor is measured and written to the
 * bottom right corner of the window and moved back to its original. */

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

void draw_position(int bot, int right, int y, int x) {
  char* msg;
  sprintf(msg, "(%d, %d)", y, x);

  size_t len = strlen(msg);

  mvprintw(bot, right-len, "%s", msg);
  refresh();
}

int main(int argc, char* argv[argc]) {
  initscr();

  int cols, rows;
  getmaxyx(stdscr, cols, rows);

  char ch = '\0';
  while ((ch = getch()) != '~') {
    int y, x;
    getyx(stdscr, y, x);

    draw_position(cols-1, rows-1, y, x);

    move(y, x+1);
    refresh();
  }

  getch();
  endwin();

  return EXIT_SUCCESS;
}
