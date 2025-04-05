#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
  float x;
  float y;
  int width;
  int height;
  float speed;
} Player;

void initPlayer();
void updatePlayer();
void drawPlayer();
void destroyPlayer();

#endif
