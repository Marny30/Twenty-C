#include "common.h"
#include "model.h"
#include <unistd.h>             /* usleep */

#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_DOWN 66
#define KEY_UP 65 
#define KEY_SELECT 32

struct Controller{
  double waittime;          /* in ms */
};

void controller_main(GameModel *g);
void moveCursor(GameModel *g, int dx, int dy);
