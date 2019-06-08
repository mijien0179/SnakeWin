#include "InputFunc.h"

const KBMFC keydownEventList[] = {
	 {SGS_BEFORE, Keydown_Before}
	,{SGS_GAME, Keydown_Game}
};

const int sKeydownEventList = sizeof(keydownEventList);

void Keydown_Before PARAMETER
{
	switch (wParam) {
	case VK_UP:
	case VK_DOWN:
	case VK_LEFT:
	case VK_RIGHT:
		Game_State = SGS_GAME;
		SnakeDirection = wParam;
		SnakeBD[0].x = SnakeBD[0].y = SNAKE_MAP_SIZE / 2 ;
		SetTimer(hWnd, TEC_CALCULATE, 150, Snake_CalculateFunction);
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}

}

void Keydown_Game PARAMETER
{
	if (SnakeDirection == VK_UP) {
		switch (wParam) {
		case VK_LEFT:
		case VK_RIGHT:
			SnakeDirection = wParam;
			break;
		}
	}
	else if (SnakeDirection == VK_DOWN) {
		switch (wParam) {
		case VK_LEFT:
		case VK_RIGHT:
			SnakeDirection = wParam;
			break;
		}
	}
	else if (SnakeDirection == VK_LEFT) {
		switch (wParam) {
		case VK_UP:
		case VK_DOWN:
			SnakeDirection = wParam;
			break;
		}
	}else if (SnakeDirection == VK_RIGHT) {
		switch (wParam) {
		case VK_UP:
		case VK_DOWN:
			SnakeDirection = wParam;
			break;
		}
	}
}