#include "common.h"

#define COL_DEF "\e[39m"
#define COL_01 "\e[38;5;186"
#define COL_02 "\e[38;5;1"
#define COL_03 "\e[38;5;6"
#define COL_04 "\e[38;5;4"
#define COL_05 "\e[38;5;5"
#define COL_06 "\e[38;5;2"
#define COL_07 "\e[38;5;167"
#define COL_08 "\e[38;5;92"
#define COL_09 "\e[38;5;166"
#define COL_10 "\e[38;5;246"
#define COL_11 "\e[38;5;249"
#define COL_12 "\e[38;5;11"
#define COL_13 "\e[38;5;13"
#define COL_14 "\e[38;5;166"
#define COL_15 "\e[38;5;238"
#define COL_16 "\e[38;5;26"
#define COL_17 "\e[38;5;166"
#define COL_18 "\e[38;5;166"
#define COL_19 "\e[38;5;137"
#define COL_20 "\e[38;5;166"

#define COL_BAKGD_DEF "\e[49m"
#define COL_BAKGD_CURS "\e[48;5;232"
#define COL_BAKGD_SELEC "\e[48;5;233"

struct View{
  char* color[20];
};

void initView(View *v);
  
void caseView(View v, Case c);
void gameView(View v, GameModel g);
void clear();
