#include "InputFunc.h"

const KBMFC keydownEventList[] = {
	 {SGS_BEFORE, Keydown_Before}
	,{SGS_GAME, Keydown_Game}
	,{SGS_ENDED, Keydown_Ended}
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
		SnakeDirection = SnakeNextDirection = wParam;
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
			SnakeNextDirection = wParam;
			break;
		}
	}
	else if (SnakeDirection == VK_DOWN) {
		switch (wParam) {
		case VK_LEFT:
		case VK_RIGHT:
			SnakeNextDirection= wParam;
			break;
		}
	}
	else if (SnakeDirection == VK_LEFT) {
		switch (wParam) {
		case VK_UP:
		case VK_DOWN:
			SnakeNextDirection = wParam;
			break;
		}
	}else if (SnakeDirection == VK_RIGHT) {
		switch (wParam) {
		case VK_UP:
		case VK_DOWN:
			SnakeNextDirection = wParam;
			break;
		}
	}
}

void Keydown_Ended PARAMETER
{
	switch (wParam) {
	case 'R':
		Game_State = SGS_BEFORE;
		Snake_GameInit();
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}
}