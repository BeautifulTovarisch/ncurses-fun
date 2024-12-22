/** GetPass
 * Prompts the user to enter their password and reads the input to a buffer in
 * memory. An ncurses equivalent to the deprecated getpass() function. */

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

int main(int argc, char* argv[argc]) {
  initscr();

  char name[51];
  mvprintw(3, 10, "Enter your name: ");
  refresh();
  getnstr(name, 50);

  // noecho prevents keystrokes from being written to the terminal
  char pass[10];
  mvprintw(5, 6, "Enter your password: ");
  refresh();

  noecho();
  getnstr(pass, 9);

  mvprintw(6, 6, "Your password is %d characters long", strlen(pass));
  refresh();

  getch();
  endwin();
  return EXIT_SUCCESS;
}
