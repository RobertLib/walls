#include <raylib.h>
#include "player.h"
#include "globals.h"
#include "game.h"
#include "walls.h"

static Player player;

void initPlayer() {
  player.width = 30;
  player.height = 30;
  player.x = SCREEN_WIDTH / 2 - player.width / 2;
  player.y = SCREEN_HEIGHT - player.height - 20;
  player.speed = 300;
}

static void handleInput() {
  float deltaTime = GetFrameTime();

  if (IsKeyDown(KEY_RIGHT)) {
    player.x += player.speed * deltaTime;
  }
  if (IsKeyDown(KEY_LEFT)) {
    player.x -= player.speed * deltaTime;
  }
}

void updatePlayer() {
  handleInput();

  if (player.x < 0) {
    player.x = 0;
  }
  if (player.x + player.width > SCREEN_WIDTH) {
    player.x = SCREEN_WIDTH - player.width;
  }

  if (checkWallsPlayerCollision(&player)) {
    setGameState(GAME_STATE_GAMEOVER);
  }
}

void drawPlayer() {
  DrawRectangle(player.x, player.y, player.width, player.height, BLUE);
}

void destroyPlayer() {

}
