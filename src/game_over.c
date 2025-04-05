#include <raylib.h>
#include "game_over.h"
#include "globals.h"
#include "game.h"

extern float score;

void initGameOver() {

}

void updateGameOver() {
  if (IsKeyPressed(KEY_SPACE)) {
    setGameState(GAME_STATE_PLAYING);
  }
}

void drawGameOver() {
  DrawText("Game Over",
           SCREEN_WIDTH / 2 - MeasureText("Game Over", 20) / 2,
           SCREEN_HEIGHT / 2 - 40, 20, WHITE);

  DrawText("Press SPACE to restart",
           SCREEN_WIDTH / 2 - MeasureText("Press SPACE to restart", 20) / 2,
           SCREEN_HEIGHT / 2, 20, WHITE);

  DrawText(TextFormat("Score: %.2f", score),
           SCREEN_WIDTH / 2 - MeasureText(TextFormat("Score: %.2f", score), 20) / 2,
           SCREEN_HEIGHT / 2 + 40, 20, WHITE);
}

void destroyGameOver() {

}
