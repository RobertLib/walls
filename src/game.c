#include "game.h"
#include "playing.h"
#include "game_over.h"
#include "victory.h"

static GameState currentGameState = GAME_STATE_PLAYING;

void initGame() {
  switch (currentGameState) {
    case GAME_STATE_PLAYING:
      initPlaying();
      break;
    case GAME_STATE_GAMEOVER:
      initGameOver();
      break;
    case GAME_STATE_VICTORY:
      initVictory();
      break;
  }
}

void updateGame() {
  switch (currentGameState) {
    case GAME_STATE_PLAYING:
      updatePlaying();
      break;
    case GAME_STATE_GAMEOVER:
      updateGameOver();
      break;
    case GAME_STATE_VICTORY:
      updateVictory();
      break;
  }
}

void drawGame() {
  switch (currentGameState) {
    case GAME_STATE_PLAYING:
      drawPlaying();
      break;
    case GAME_STATE_GAMEOVER:
      drawGameOver();
      break;
    case GAME_STATE_VICTORY:
      drawVictory();
      break;
  }
}

void destroyGame() {
  switch (currentGameState) {
    case GAME_STATE_PLAYING:
      destroyPlaying();
      break;
    case GAME_STATE_GAMEOVER:
      destroyGameOver();
      break;
    case GAME_STATE_VICTORY:
      destroyVictory();
      break;
  }
}

void setGameState(GameState state) {
  if (state == currentGameState) {
    return;
  }

  destroyGame();
  currentGameState = state;
  initGame();
}
