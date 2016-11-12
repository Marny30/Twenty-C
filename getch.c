#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int getch(void)
{
        struct termios oldt, newt;
        int ch, chtmp=0;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~ECHO;
        newt.c_lflag &= ~ICANON; /* disable buffered i/o */

        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
       
        do {
            ch = chtmp;
            chtmp = getchar();
        } while (chtmp!=EOF);

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        
        return ch;
}
