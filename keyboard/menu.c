/** Menu
 * Display a simple navigable menu. Menu options can be selected with arrow keys:
 *
 * Main Menu
 *
 *    OPTION1
 *    OPTION2
 *    ...
 *    OPTIONN
 *
 *      Instructions
 * */

#include <stdlib.h>
#include <ncurses.h>

// Options may be at most 20 characters
#define MAX_LEN 21
#define NUM_OPTIONS 6

static char* title = "Main Menu";
static char menu[NUM_OPTIONS][MAX_LEN] = {
  "Email",
  "Browser",
  "Word",
  "Finances",
  "Settings",
  "Exit"
};

// Draw the main menu and highlight the selection. [selection] is assumed to
// be valid, thus, the client must compute the selection % NUM_OPTIONS
void draw_menu(int selection) {
  clear();
  addstr(title);

  // The client should ensure this is never run.
  if (selection < 0 || selection >= NUM_OPTIONS) {
    mvprintw(0, 0, "Invalid selection %d. Exiting...\n", selection);
    refresh();
    napms(1000);

    endwin();
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < NUM_OPTIONS; i++) {
    if (i == selection) {
      // Highlight the option.
      attron(A_REVERSE);
    }

    // Options start three lines below the origin and are double-spaced.
    mvaddstr(3 + (2*i), 20, menu[i]);
    attroff(A_REVERSE);
  }

  mvaddstr(17, 25, "Use arrow keys to move; Enter to select");
  refresh();
}

// update_selection computes the index of the new selection depending on whether KEY_UP or
// KEY_DOWN is pressed.
int update_selection(int old, int key) {
  if (key == KEY_DOWN) {
    return (old + 1) % NUM_OPTIONS;
  }

  // Pressing up on the first option wraps around to the end.
  if (old <= 0) {
    return NUM_OPTIONS - 1;
  }

  return old - 1;
}

int main(int argc, char* argv[argc]) {
  initscr();
  keypad(stdscr, TRUE);

  int selection = 0;
  draw_menu(selection);

  noecho();

  // Absolutely important that key is an int and not a char!
  int key;
  while ((key = getch()) != '\n') {
    selection = update_selection(selection, key);
    draw_menu(selection);
  }
  echo();

  endwin();
  return EXIT_SUCCESS;
}
