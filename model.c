#include "model.h"

int initModel(GameModel *g){
  srand(time(NULL));
  for (int i=0; i<7; i++){
    for (int j=0; j<10; j++){
      g->cases[i][j].x = 0;
      g->cases[i][j].y = 0;
      g->cases[i][j].nombre = 0;
    }
  }
  g->alive = 1;
  g->cursor->target = NULL;
  g->cursor.carrying = 0;
  newline(g, 4);
  newline(g, 4);
  /* recherche max */
  gravity_move(g);
}

void tick(GameModel *g, double t){
  g->timeleft -= t;
  if (g->timeleft <= 0){
    newline(g, g->max);
    g->timeleft = TIME_PER_TURN;
  }
}

void newline(GameModel *g, const int max){
  /* vérification si mort */
  for (int i=0; i<7; i++){
    if (g->cases[i][0].nombre){
      g->alive = 0;
      return;
    }
  }
  /* décallage */
  for (int i=0; i<7; i++){
    for (int j=1; j<9; j++){
      if (g->cases[i][j].nombre){
        g->cases[i][j].x = g->cases[i][j-1].x;
        g->cases[i][j].y = g->cases[i][j-1].y;
        g->cases[i][j].nombre = g->cases[i][j-1].nombre;
      }
    }
  }
  /* création nouvelle ligne */
  int r;
  for (int i=0; i<7; i++){
    do{ /* On génère des nombres différents de ceux présent au dessus */
      r = rand()%max;
      g->cases[i][9].nombre = r;
    } while (g->cases[i][8].nombre == r);
  }
  //gravity_move(g);
}

int gravity_move(GameModel *g){
  int tmp_max;
  for (int i=0; i<7; i++){
    for (int j=0; j<9; j++){
      /* on commence par la premiere rangée sur laquelle on applique grav */
      tmp_max = move(&g->cases[i][j], &g->cases[i][j+1]);
      if (g->max < tmp_max)
        g->max = tmp_max;
    }
  }
}

int move (Case *c1, Case *c2){
    /* si limitrophes et c2 vide */
    if (!c2->nombre){
      c2->x = c1->x;
      c2->y = c1->y;
      c2->nombre = c1->nombre;
      c1->nombre = 0;
      return c2->nombre;
    }
    /* si limitrophes et même valeurs */
    else return fusion(c1, c2);
}

int fusion (Case *c1, Case *c2){
  if (c1->nombre==c2->nombre){
    c2->x = c1->x;  c2->y = c1->y;
    c2->nombre++;
    c1->nombre = 0;
    return c2->nombre;
  }
  else return -1;
}
