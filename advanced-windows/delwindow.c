/** Delete Window
 * This program shows how a window can be deleted using the delwin() function. */

#include <stdlib.h>
#include <ncurses.h>

WINDOW* init_window() {
  WINDOW* two = newwin(0, 0, 0, 0);
  if (!two) {
    addstr("error allocating window 'two'. Exiting...");
    endwin();

    exit(EXIT_FAILURE);
  }

  waddstr(two, "This is the second window!");

  return two;
}

int main(int argc, char* argv[argc]) {
  initscr();

  addstr("This is the first window");
  refresh();

  // Create a window, add some text and then delete
  WINDOW* two = init_window();
  wrefresh(two);
  getch();

  delwin(two);
  touchwin(stdscr);
  refresh();

  getch();
  endwin();

  return EXIT_SUCCESS;
}
