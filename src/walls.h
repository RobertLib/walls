#ifndef WALLS_H
#define WALLS_H

#define NUM_WALLS 100
#define GAP_BETWEEN_WALLS 200

#include <stdbool.h>

typedef struct Player Player;

void initWalls();
void updateWalls();
void drawWalls();
void destroyWalls();
bool checkWallsPlayerCollision(Player *player);

#endif
