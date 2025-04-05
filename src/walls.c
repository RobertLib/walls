#include "walls.h"
#include "wall.h"
#include "globals.h"
#include "physics.h"
#include "game.h"
#include "player.h"

static Wall walls[NUM_WALLS];

void initWalls() {
  for (int i = 0; i < NUM_WALLS; i++) {
    initWall(&walls[i], 0, (i - NUM_WALLS + 1) * GAP_BETWEEN_WALLS);
  }
}

void updateWalls() {
  for (int i = 0; i < NUM_WALLS; i++) {
    updateWall(&walls[i]);
  }

  if (walls[0].y >= SCREEN_HEIGHT) {
    setGameState(GAME_STATE_VICTORY);
  }
}

void drawWalls() {
  for (int i = 0; i < NUM_WALLS; i++) {
    if (walls[i].y + walls[i].height >= 0 && walls[i].y <= SCREEN_HEIGHT) {
      drawWall(&walls[i]);
    }
  }
}

void destroyWalls() {

}

bool checkWallsPlayerCollision(Player *player) {
  for (int i = 0; i < NUM_WALLS; i++) {
    if (walls[i].y + walls[i].height >= 0 && walls[i].y <= SCREEN_HEIGHT) {
      if (checkCollision(player->x, player->y, player->width, player->height,
                         walls[i].x, walls[i].y, walls[i].gapPosition, walls[i].height)) {
        return true;
      }

      if (checkCollision(player->x, player->y, player->width, player->height,
                         walls[i].x + walls[i].gapPosition + walls[i].gapWidth, walls[i].y,
                         walls[i].width - (walls[i].gapPosition + walls[i].gapWidth), walls[i].height)) {
        return true;
      }
    }
  }

  return false;
}
