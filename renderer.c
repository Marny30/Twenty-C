#include "renderer.h"

void initView(View *v){
  int icolor[21] = {0,
                   186, 1, 6, 4, 5,
                   2, 167, 92, 166, 246,
                   249, 11, 13, 166, 238,
                   26, 166, 166, 137, 166};
  char buf[20];
  for(int i=0; i<20; i++){
    //itoa(icolor[i], buf, 10);
    //strcpy(v->color[i], strcat("\e[38;5;",buf));
    sprintf(v->color[i], "\033[38;5;%dm", icolor[i]);
  }
}
  
void caseView(View v, Case c){
  printf("%s%2d",v.color[c.nombre], c.nombre);
}

void gameView(View v, GameModel g){
  printf(COL_DEF);
  printf("time left: %3.2f\n"
         "score : %d\n", g.timeleft, g.max);
  for (int j=0; j<10; j++){
    for (int i=0; i<7; i++){
      if (g.cursor.target->x == i && g.cursor.target->y == j)
        g.cursor.carrying ? printf(COL_BAKGD_CURS) : printf(COL_BAKGD_SELEC);
      caseView(v, g.cases[i][j]);
      printf(COL_BAKGD_DEF" ");
    }
    printf("\n");
  }
}

void clear(){
  system("clear");
}

