/** Center
 * This program demonstrates how text can be centered in the window. This is
 * accomplished via a simple algorithm:
 *
 *  1. Measure height and width of the window
 *  2. Position the cursor in the midpoint of the screen (row, (width - len(str))/2)
 *     This is to accommodate the width of the text.
 *  3. Draw and refresh as normal */

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

// draw_center horizontally centers [text] in [row]. The width of the window
// is provided here to avoid needless recomputation.
void draw_center(int width, int row, char* text) {
  size_t len = strlen(text);

  int offset = width - len;
  mvaddstr(row, offset >> 1, text);

  refresh();
}

int main(int argc, char* argv[argc]) {
  initscr();

  // For this program, we don't need the rows.
  int rows, cols;
  getmaxyx(stdscr, rows, cols);

  draw_center(cols, 1, "Row 1 Centered Text");
  draw_center(cols, 3, "Row 3 Centered Text");
  draw_center(cols, 5, "Row 5 Centered Text");
  draw_center(cols, 7, "Row 7 Centered Text");

  getch();
  endwin();

  return EXIT_SUCCESS;
}
