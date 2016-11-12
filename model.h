#include "common.h"

#define TIME_PER_TURN 10

struct GameModel{
  struct Case[7][10] cases;
  struct Cursor sel;
  int max;
  int alive;
  int timeleft;
};

struct Cursor{
  int x, y;
  
}
  
struct Case{
  int nombre;
  int x, y;
};

int gravity_move(Case c1);
int move(Case c1, Case c2);     /* -1 if not possible */
int fusion(Case c1, Case c2);   /* -1 " ",
                                   nombre sinon*/
void newline();

int getmax();
