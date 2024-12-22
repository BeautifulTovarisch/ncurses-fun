/** Data
 * Demonstrates some of the formatting options of printw() by outputting data in
 * a tabular format. */

#include <stdlib.h>
#include <ncurses.h>

#define COL1 5
#define COL2 38

int main(int argc, char* argv[argc]) {
  initscr();

  // Right-justified
  mvprintw(5, COL1, "%30s", "Name:");
  // Left-justified (with '-')
  mvprintw(5, COL2, "%-30s", "Anthony" );

  mvprintw(7, COL1, "%30s", "Company:");
  mvprintw(7, COL2, "%-30s", "Great Minds");

  mvprintw(9, COL1, "%30s", "Title:");
  mvprintw(9, COL2, "%-30s", "Staff Engineer");

  mvprintw(11, COL1, "%30s", "Date Hired:");
  mvprintw(11, COL2, "%-30s", "2024-10-07");

  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
