#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

#define EXIT_KEY 'q'

struct termios originalTermios;

/* It restores terminal's original attributes when program exits */
void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios);
}

/*
* In **canonical** mode (alias cooked mode), the program receives the entire line of text only after you press `Enter`.
* In **raw** mode, in contrast, the program reacts instantly to every single key you press.
* Raw mode is essential for complex interfaces like text editors.
*/
void enableRawMode() {
    struct termios raw;

    /* 
    * tcgetattr() is responsible for reading current attributes on a terminal 
    * Attributes are gonna be put into originalTermios first in order to have a global backup of them
    */
    tcgetattr(STDIN_FILENO, &originalTermios);

    /* In this way, disableRawMode() is called every time the program exits */
    atexit(disableRawMode);

    struct termios raw = originalTermios;

    /* 
    * Once attributes are in &raw variable, is possible to edit them.
    * ECHO is responsible for printing characters to the terminal
    * 
    * ECHO is located into local flags (i.e. c_lflags) and 
    * by this operation, ECHO is going to be disabled (turning at zero the bit corrisponding to it)
    *
    */
    raw.c_lflag &= ~(ECHO);

    /* 
    * tcsetattr() is responsible for applying every change made to attributes 
    * TCSAFLUSH specifies to wait for every pending output
    */
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}



int main(void) {
    enableRawMode();
    char currentChar;
    /*
    * read()'s function reads one byte from standard input (i.e. STDIN_FILENO) 
    * till no other bytes are left; Every byte goes to &c.
    * 
    * read() returns the number of bytes that it read, 
    * and will return 0 when it reaches the end of a file
    */ 
    while (read(STDIN_FILENO, &currentChar, 1) == 1 && currentChar != EXIT_KEY);

    return 0;
}