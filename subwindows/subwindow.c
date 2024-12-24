/** Subwindow
 * A basic program demonstrating NCurse's subwindows. Subwindows are ordinary
 * windows except they share memory with their parent. */

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

// Basic error-handling wrapper for subwin.
WINDOW* init_subwin(WINDOW* parent, int rows, int cols, int y, int x) {
  WINDOW* sub = subwin(parent, rows, cols, y, x);
  if (!sub) {
    addstr("unable to create subwindow");
    refresh();
    endwin();

    exit(EXIT_FAILURE);
  }

  return sub;
}

int main(int argc, char* argv[argc]) {
  initscr();

  if (start_color() == OK) {
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  }

  const char* msg = "I am the child window";
  const char* msg2 = "I am the grandchild window";

  // Color the 'parent'
  bkgd(COLOR_PAIR(1));
  addstr("I am the parent window");

  // Create a subwindow of the standard screen.
  size_t len = strlen(msg);
  size_t len2 = strlen(msg2);
  WINDOW* sub = init_subwin(stdscr, 10, len+len2+5, 10, 30);
  // Render the 'child' window.
  wbkgd(sub, COLOR_PAIR(2));
  waddstr(sub, msg);

  int y, x;
  getmaxyx(sub, y, x);

  // derwin positions the subwindow relative to the origin of the parent instead
  // of the screen.
  WINDOW* sub2 = derwin(sub, 1, len2+1, y>>1, (x-len2)>>1);
  wbkgd(sub2, COLOR_PAIR(3));
  waddstr(sub2, msg2);

  refresh();
  wrefresh(sub);
  wrefresh(sub2);

  getch();

  // Deleting the child does not clear its text because it is still referenced
  // by the parent. This text must be cleared using any of the normal methods.
  int cy, cx;
  getyx(sub2, cy, cx);

  // Move the cursor to the child's origin before freeing memory.
  wmove(sub2, 0, 0);
  delwin(sub2);

  // Clear from the origin to the bottom of the parent screen.
  // TODO: Find a more idiomatic way to do this.
  wclrtobot(sub);
  wmove(sub, 0, 0);
  wrefresh(sub);

  getch();

  endwin();
  return EXIT_SUCCESS;
}
