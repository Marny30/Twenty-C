#include "model.h"

int initModel(GameModel *g){
  srand(time(NULL));
  for (int i=0; i<7; i++){
    for (int j=0; j<10; j++){
      g->cases[i][j].x = i;
      g->cases[i][j].y = j;
      g->cases[i][j].nombre = 0;
    }
  }
  g->timeleft = TIME_PER_TURN;
  g->alive = 1;
  g->max=4;
  g->cursor.target = &g->cases[0][0];
  g->cursor.carrying = 0;
  newline(g);
  /* recherche max */
  int tmp_max=0;
  for (int i=0; i<7; i++){
    if (g->max < g->cases[i][9].nombre)
      g->max = g->cases[i][9].nombre;
  }
  newline(g);
  gravity_move(g);
}

void tick(GameModel *g, float t){
  g->timeleft -= t;
  if (g->timeleft <= 0){
    newline(g);
    g->timeleft = TIME_PER_TURN;
  }
}

void newline(GameModel *g){
  /* vérification si mort */
  for (int i=0; i<7; i++){
    printf("%d",g->cases[i][0].nombre);
    if (g->cases[i][0].nombre>0){
      g->alive = 0;
      printf("test");
      return;
      printf("test2");
    }
  }
  /* décallage */
  for (int i=0; i<7; i++){
    for (int j=0; j<9; j++){
      
        g->cases[i][j].x = g->cases[i][j+1].x;
        g->cases[i][j].y = j;
        g->cases[i][j].nombre = g->cases[i][j+1].nombre;
      
    }
  }
  /* création nouvelle ligne */
  int r;
  for (int i=0; i<7; i++){
    do{  // On génère des nombres différents de ceux présent au dessus 
        r = 1+rand()%(g->max);
        g->cases[i][9].nombre = r;
        g->cases[i][9].x = i;
        g->cases[i][9].y = 9;
      } while (g->cases[i][8].nombre == r);
      } 
  gravity_move(g);
}

int gravity_move(GameModel *g){
  int tmp_max = 0;
  for (int i=0; i<7; i++){
    for (int j=8; j>=0; j--){
      /* on commence par la premiere rangée sur laquelle on applique grav */
      if (g->cases[i][j].nombre>0 &&
          !(g->cursor.target->x == i && g->cursor.target->y == j && g->cursor.carrying))
        tmp_max = move(&g->cases[i][j], &g->cases[i][j+1]);

      if (g->max < tmp_max)
        g->max = tmp_max;
    }
  }

}

int move (Case *c1, Case *c2){
    /* si limitrophes et c2 vide */
    if (!c2->nombre){
      c2->nombre = c1->nombre;
      c1->nombre = 0;
      return c2->nombre;
    }
    /* si limitrophes et même valeurs */
    else return fusion(c1, c2);
}

int fusion (Case *c1, Case *c2){
  if (c1->nombre==c2->nombre){
    c2->nombre++;
    c1->nombre = 0;
    return c2->nombre;
  }
  else return -1;
}
