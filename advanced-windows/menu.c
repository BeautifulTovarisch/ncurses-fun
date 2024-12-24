/** Menu
 * This program draws a menu as a separate window and demonstrates "navigation"
 * between multiple windows */

#include <stdlib.h>
#include <ncurses.h>

WINDOW* init_help(void) {
  WINDOW* help = newwin(10, 30, 4, 6);

  if (!help) {
    addstr("unable to allocate help menu");
    endwin();

    exit(EXIT_FAILURE);
  }

  mvwaddstr(help, 1, 7, "Help menu screen");
  mvwaddstr(help, 5, 3, "Press '~' to quit");
  mvwaddstr(help, 8, 4, "Press ENTER to go back");

  return help;
}

void draw_help(WINDOW* help) {
  touchwin(help);
  wrefresh(help);
}

int main(int argc, char* argv[argc]) {
  initscr();

  addstr("Program\n");
  addstr("Press '+' for help\n\n");
  refresh();
  noecho();

  WINDOW* help = init_help();

  int ch;
  while ((ch = getch()) != '~') {
    if (ch == '+') {
      draw_help(help);
    } else {
      addch(ch);
      touchwin(stdscr);
    }

    refresh();
  }

  endwin();

  return EXIT_SUCCESS;
}
