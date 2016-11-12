#include "common.h"
#include "model.h"
#include <string.h>             /* strcat, strcpy */
#include <stdlib.h>
#include <stdio.h>

#define COL_DEF "\e[39m"

#define COL_BAKGD_DEF "\033[49m"
#define COL_BAKGD_CURS "\033[48;5;235m"
#define COL_BAKGD_SELEC "\033[48;5;240m"

struct View{
  char color[12][20];
};
typedef struct View View;

void initView(View *v);
  
void caseView(View v, Case c);
void gameView(View v, GameModel g);
void clear();
