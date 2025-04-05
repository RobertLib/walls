#include <raylib.h>
#include "victory.h"
#include "globals.h"
#include "game.h"

extern float score;

void initVictory() {

}

void updateVictory() {
  if (IsKeyPressed(KEY_SPACE)) {
    setGameState(GAME_STATE_PLAYING);
  }
}

void drawVictory() {
  DrawText("Victory",
           SCREEN_WIDTH / 2 - MeasureText("Victory", 20) / 2,
           SCREEN_HEIGHT / 2 - 40, 20, WHITE);

  DrawText("Press SPACE to restart",
           SCREEN_WIDTH / 2 - MeasureText("Press SPACE to restart", 20) / 2,
           SCREEN_HEIGHT / 2, 20, WHITE);

  DrawText(TextFormat("Score: %.2f", score),
           SCREEN_WIDTH / 2 - MeasureText(TextFormat("Score: %.2f", score), 20) / 2,
           SCREEN_HEIGHT / 2 + 40, 20, WHITE);
}

void destroyVictory() {

}
