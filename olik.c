#include <unistd.h>

#define EXIT_KEY 'q'

int main(void) {

    char c;
    /*
    * read()'s function reads one byte from standard input (i.e. STDIN_FILENO) 
    * till no other bytes are left; Every byte goes to &c.
    * 
    * read() returns the number of bytes that it read, 
    * and will return 0 when it reaches the end of a file
    */ 
    while (read(STDIN_FILENO, &c, 1) == 1 && c != EXIT_KEY);

    return 0;
}