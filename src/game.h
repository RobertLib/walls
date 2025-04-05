#ifndef GAME_H
#define GAME_H

typedef enum {
  GAME_STATE_PLAYING,
  GAME_STATE_GAMEOVER,
  GAME_STATE_VICTORY
} GameState;

void initGame();
void updateGame();
void drawGame();
void destroyGame();
void setGameState(GameState state);

#endif
