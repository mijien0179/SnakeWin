#include "timerFunc.h"

void CALLBACK Snake_CalculateFunction CALLBACK_PARAM
{
	for (int i = SnakeBodySize - 1; i >= 1; --i) {
		SnakeBD[i] = SnakeBD[i - 1];
	}

	SnakeBody * p = SnakeBD;
	switch (SnakeDirection) {
	case VK_UP:
		p->y -= 1;
		if (p->y < 0) {
			Game_State = SGS_ENDED;
		}
		break;
	case VK_DOWN:
		p->y += 1;
		if (p->y >= SNAKE_MAP_SIZE) {
			Game_State = SGS_ENDED;
		}
		break;
	case VK_LEFT:
		p->x -= 1;
		if (p->x < 0) {
			Game_State = SGS_ENDED;
		}
		break;
	case VK_RIGHT:
		p->x += 1;
		if (p->x >= SNAKE_MAP_SIZE) {
			Game_State = SGS_ENDED;
		}
		break;
	}

	for (int i = 1; i < SnakeBodySize; ++i) {
		if (SnakeBD[0].x == SnakeBD[i].x &&
			SnakeBD[0].y == SnakeBD[i].y) {
			Game_State = SGS_ENDED;
			break;
		}
	}

	if (FoodPosition.x == SnakeBD[0].x &&
		FoodPosition.y == SnakeBD[0].y) {
		if (SNAKE_BODY_SIZE > SnakeBodySize) {
			SnakeBodySize++;
		}
		Snake_NewFood();
	}

	if (Game_State == SGS_ENDED) {
		KillTimer(hWnd, TEC_CALCULATE);
		InvalidateRect(hWnd, NULL, TRUE);
	}

	InvalidateRect(hWnd, NULL, FALSE);
}

void Snake_NewFood() {

	if (Game_State == SGS_BEFORE) {
		FoodPosition.x = rand() % SNAKE_MAP_SIZE;
		FoodPosition.y = rand() % SNAKE_MAP_SIZE;
	}
	else if (Game_State == SGS_GAME) {
		int retry = 0;
		do {
			FoodPosition.x = rand() % SNAKE_MAP_SIZE;
			FoodPosition.y = rand() % SNAKE_MAP_SIZE;

			for (int i = 0; i < SnakeBodySize; ++i) {
				if (FoodPosition.x == SnakeBD[i].x &&
					FoodPosition.y == SnakeBD[i].y) {
					retry = 1;
				}
			}
		} while (retry);
	}
}