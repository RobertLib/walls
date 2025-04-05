#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Output fragment color
out vec4 finalColor;

// Uniform variables
uniform float iTime;      // Shader execution time in seconds
uniform vec2 iResolution; // Viewport resolution (in pixels)

void main() {
  vec2 uv = fragTexCoord;

  // Plasma formula
  float v1 = sin((uv.x * 10.0) + iTime);
  float v2 = sin((uv.y * 10.0) + iTime);
  float v3 = sin((uv.x * 10.0 + uv.y * 10.0 + iTime) * 0.5);
  float v4 = sin(sqrt(100.0 * ((uv.x - 0.5) * (uv.x - 0.5) + (uv.y - 0.5) * (uv.y - 0.5))) + iTime);

  // Combine plasma waves
  float cx = uv.x + 0.5 * sin(iTime / 2.0);
  float cy = uv.y + 0.5 * cos(iTime / 3.0);
  float v5 = sin(sqrt(100.0 * ((cx - 0.5) * (cx - 0.5) + (cy - 0.5) * (cy - 0.5))) + iTime);

  float final = (v1 + v2 + v3 + v4 + v5) / 5.0;

  // Create nice color gradients
  vec3 col;
  col.r = sin(final * 3.14159 + iTime) * 0.5 + 0.5;
  col.g = sin(final * 3.14159 + iTime + 2.0) * 0.5 + 0.5;
  col.b = sin(final * 3.14159 + iTime + 4.0) * 0.5 + 0.5;

  // Fade plasma out a bit so it doesn't interfere with gameplay
  finalColor = vec4(col * 0.7, 0.4);
}
