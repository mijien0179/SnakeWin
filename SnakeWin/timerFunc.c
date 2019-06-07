#include "timerFunc.h"

void CALLBACK Snake_CalculateFunction CALLBACK_PARAM
{
	for (int i = SnakeBodySize - 1; i >= 1; --i) {
		SnakeBD[i] = SnakeBD[i-1];
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
	   
	if (Game_State == SGS_ENDED) {
		KillTimer(hWnd, TEC_CALCULATE);
		InvalidateRect(hWnd, NULL, TRUE);
	}

	InvalidateRect(hWnd, NULL, FALSE);
}
