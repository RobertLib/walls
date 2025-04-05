#include <raylib.h>
#include "playing.h"
#include "globals.h"
#include "player.h"
#include "walls.h"

extern float score;

static Shader plasmaShader;
static RenderTexture2D plasmaTarget;
static float plasmaTime = 0;

void initPlaying() {
  initPlayer();
  initWalls();

  score = 0;

  plasmaShader = LoadShader("src/plasma.vs", "src/plasma.fs");
  int resolutionIndex = GetShaderLocation(plasmaShader, "iResolution");
  float resolution[] = { (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
  SetShaderValue(plasmaShader, resolutionIndex, resolution, SHADER_UNIFORM_VEC2);

  plasmaTarget = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);

  plasmaTime = 0;
}

void updatePlaying() {
  float deltaTime = GetFrameTime();
  score += deltaTime;

  plasmaTime += deltaTime;
  SetShaderValue(plasmaShader, GetShaderLocation(plasmaShader, "iTime"), &plasmaTime, SHADER_UNIFORM_FLOAT);

  updatePlayer();
  updateWalls();
}

void drawPlaying() {
  BeginShaderMode(plasmaShader);
  DrawTextureRec(plasmaTarget.texture,
                 (Rectangle){ 0, 0, (float)plasmaTarget.texture.width, (float)-plasmaTarget.texture.height },
                 (Vector2){ 0, 0 }, WHITE);
  EndShaderMode();

  drawPlayer();
  drawWalls();

  DrawText(TextFormat("%03i", (int)score), 10, 10, 20, BLUE);
}

void destroyPlaying() {
  destroyPlayer();
  destroyWalls();

  UnloadShader(plasmaShader);
  UnloadRenderTexture(plasmaTarget);
}
