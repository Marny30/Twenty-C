#include "common.h"

#define KEY_RIGHT
#define KEY_LEFT
#define KEY_DOWN
#define KEY_UP
#define KEY_SELECT

struct Controller{
  double waittime;          /* in ms */
  
};

int controller_main(GameModel *g);
int get_key();
void key_handling(GameModel *g, int key);
void switchmodeCursor(GameModel *g);
void moveCursor(GameModel *g);
