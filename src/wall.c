#include <raylib.h>
#include "wall.h"
#include "globals.h"

void initWall(Wall *wall, float x, float y) {
  wall->x = x;
  wall->y = y;
  wall->width = SCREEN_WIDTH;
  wall->height = 30;
  wall->speed = 50;
  wall->gapWidth = 100;
  wall->gapPosition = GetRandomValue(0, SCREEN_WIDTH - wall->gapWidth);
}

void drawWall(Wall *wall) {
  DrawRectangle(wall->x, wall->y, wall->gapPosition, wall->height, WHITE);

  DrawRectangle(wall->x + wall->gapPosition + wall->gapWidth, wall->y,
                wall->width - (wall->gapPosition + wall->gapWidth), wall->height, WHITE);
}

void updateWall(Wall *wall) {
  float deltaTime = GetFrameTime();

  wall->y += wall->speed * deltaTime;
  wall->speed += deltaTime;
}

void destroyWall(Wall *wall) {

}
