#include "data.h"

int SnakeDirection;
int SnakeNextDirection;

const int RefreshTime = 33;
const int SNAKE_MAP_SIZE = 25;

int StartX;
int StartY;

SGS Game_State;

int SnakeBodySize;

SnakeBody SnakeBD[SNAKE_BODY_SIZE];

Food FoodPosition;
