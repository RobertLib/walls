#include <raylib.h>
#include "globals.h"
#include "game.h"

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Walls");

  SetTargetFPS(60);

  initGame();

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_F)) {
      ToggleFullscreen();
    }

    updateGame();

    BeginDrawing();

    ClearBackground(BLACK);

    drawGame();

    EndDrawing();
  }

  destroyGame();

  CloseWindow();

  return 0;
}
