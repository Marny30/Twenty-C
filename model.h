#include "common.h"
#include <time.h>               /* time */
#include <stdlib.h>             /* srand,rand */
#define TIME_PER_TURN 10

struct Case{
  int nombre;
  int x, y;
};
typedef struct Case Case;

struct Cursor{
  Case* target;
  int carrying;                 /* bool */
}

struct GameModel{
  struct Case cases[7][10];
  struct Cursor cursor;
  int max;
  int alive;
  double timeleft;
};
typedef struct GameModel GameModel;
  

int initModel(GameModel *g);

void tick(GameModel *g, double t);
int gravity_move(GameModel *g);
int move(Case* c1, Case* c2);     /* -1 if not possible */
int fusion(Case *c1, Case *c2);   /* -1 " ",
                                   nombre sinon*/
void newline(GameModel *g, const int max);

