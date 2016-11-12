#include "controller.h"

void moveCursor(GameModel *g, int dx, int dy){
  if (g->cursor.carrying)
    move(g->cursor.target, &g->cases[g->cursor.target->x+dx][g->cursor.target->y+dy]);
  g->cursor.target = &g->cases[g->cursor.target->x+dx][g->cursor.target->y+dy];
}

void controller_main(GameModel *g){
  switch (getch()){
  case KEY_LEFT:
    if (g->cursor.target->x>0)
      moveCursor(g, -1, 0);
    break;
  case KEY_UP:
    if (g->cursor.target->y >0)
      moveCursor(g, 0, -1);
    break;
  case KEY_RIGHT:
    if (g->cursor.target->x <6)
      moveCursor(g, 1, 0);
    break;
  case KEY_DOWN:
    if (g->cursor.target->y <9)
      moveCursor(g, 0, 1);
    break;
  case KEY_SELECT:
    g->cursor.carrying = !g->cursor.carrying;
    break;
  }
  gravity_move(g);
  usleep(100000);
  tick(g, 0.1);
}
