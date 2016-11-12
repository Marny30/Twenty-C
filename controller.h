#include "common.h"

#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_DOWN 66
#define KEY_UP 65 
#define KEY_SELECT 32

struct Controller{
  double waittime;          /* in ms */
};

int controller_main(GameModel *g);
int get_key();
void key_handling(GameModel *g, int key);
void switchmodeCursor(GameModel *g);
void moveCursor(GameModel *g);
