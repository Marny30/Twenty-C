#include "common.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int controller_main(GameModel *g);
int get_key();
void key_handling(GameModel *g);
void switchmodeCursor(GameModel *g);
void moveCursor(GameModel *g);

Case selected();
