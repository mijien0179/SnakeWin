#include "data.h"

int SnakeDirection;
const int RefreshTime = 33;
const int SNAKE_MAP_SIZE = 25;

int StartX;
int StartY;

SGS Game_State;

const int MapPadding = 5;
int SnakeBodySize;

SnakeBody SnakeBD[SNAKE_BODY_SIZE];
