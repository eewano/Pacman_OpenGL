#ifndef Define_h
#define Define_h

#include "Vec2.hpp"

static Vec2i WINDOW_SIZE = { 640, 480 };
static float ASPECT_RATIO = static_cast<float>(WINDOW_SIZE.x) / WINDOW_SIZE.y;
static constexpr int DEFAULT_VERTS_COUNT = 4;

static constexpr Vec2i MAP_SIZE = { 10, 8 };
static constexpr Vec2f MAP_POS = { -0.55f, -0.35f };

#endif /* Define_h */
