#include "common.h"
#include "model.h"
#include "controller.h"
#include "renderer.h"

int main(int argc, char *argv[]){
  View view;
  GameModel game;
  //Controller controller;
  
  initView(&view);
  initModel(&game);

  clear();
  while(game.alive){
    gameView(view, game);
    controller_main(&game);
    clear();
  }
  printf("game over!");
  return 0;
}
