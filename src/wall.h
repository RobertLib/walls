#ifndef WALL_H
#define WALL_H

typedef struct Wall {
  float x;
  float y;
  int width;
  int height;
  float speed;
  int gapPosition;
  int gapWidth;
} Wall;

void initWall(Wall *wall, float x, float y);
void drawWall(Wall *wall);
void updateWall(Wall *wall);
void destroyWall(Wall *wall);

#endif
