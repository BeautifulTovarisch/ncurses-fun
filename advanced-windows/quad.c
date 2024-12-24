/** Quad Window
 * This program draws four windows in each quadrant of the terminal. Other than
 * that it doesn't introduce anything new about ncurses */

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

// Create custom color pairs corresponding to each window. In a real program, we
// should check that the terminal provides color first.
void init_colors() {
  init_pair(1, COLOR_BLACK, COLOR_BLUE);
  init_pair(2, COLOR_BLACK, COLOR_RED);
  init_pair(3, COLOR_BLACK, COLOR_GREEN);
  init_pair(4, COLOR_BLACK, COLOR_CYAN);
}

// init_window wraps newwin() and exits if the window is unable to be
WINDOW* init_window(int lines, int cols, int y, int x) {
  WINDOW* win = newwin(lines, cols, y, x);
  if (!win) {
    addstr("unable to allocate window");
    refresh();
    endwin();

    exit(EXIT_FAILURE);
  }

  return win;
}

// Draw [label] in the center of each window.
void draw_window(WINDOW* win, char* label) {
  int y, x;
  getmaxyx(win, y, x);

  size_t len = strlen(label);
  mvwaddstr(win, y >> 1, (x - len) >> 1, label);

  wrefresh(win);
}

int main(int argc, char* argv[argc]) {
  initscr();

  start_color();
  init_colors();

  refresh();

  // Measure the main window to compute each quadrant's position.
  int y, x;
  getmaxyx(stdscr, y, x);

  int midy = y >> 1;
  int midx = x >> 1;

  WINDOW* a = init_window(midy, midx, 0, 0);        // Top Left
  wbkgd(a, COLOR_PAIR(1));
  WINDOW* b = init_window(midy, midx, 0, midx);     // Top Right
  wbkgd(b, COLOR_PAIR(2));
  WINDOW* c = init_window(midy, midx, midy, 0);     // Bottom Left
  wbkgd(c, COLOR_PAIR(3));
  WINDOW* d = init_window(midy, midx, midy, midx);  // Bottom Right
  wbkgd(d, COLOR_PAIR(4));

  draw_window(a, "Window A");
  draw_window(b, "Window B");
  draw_window(c, "Window C");
  draw_window(d, "Window D");

  getch();
  endwin();

  return EXIT_SUCCESS;
}
