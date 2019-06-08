#include "procFunc.h"

const MFC procEventList[] = {
	{WM_CREATE, Snake_CreateInitFunction}
	,{WM_PAINT, Snake_PaintFunction}
	,{WM_KEYDOWN, Snake_KeyDownFunction}

};

const int sProcEventList = sizeof(procEventList);

#pragma region PAINT_FUNCTION

void Snake_PaintFunction PARAMETER
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	{
		for (int i = 0; i < sPaintEventList / sizeof(PMFC); ++i) {
			if (paintEventList[i].eventCode == Game_State) {
				paintEventList[i].func(hdc, hWnd, uMsg, wParam, lParam);
				break;
			}
		}
	}

	EndPaint(hWnd, &ps);
}
#pragma endregion

void Snake_KeyDownFunction PARAMETER
{
	for (int i = 0; i < sKeydownEventList / sizeof(KBMFC); ++i) {
		if (keydownEventList[i].eventCode == Game_State) {
			keydownEventList[i].func(hWnd, uMsg, wParam, lParam);
			return;
		}
	}

}

void Snake_CreateInitFunction PARAMETER
{
	srand((unsigned int)time(NULL));
	Snake_GameInit();
}


void Snake_GameInit()
{
	Game_State = SGS_BEFORE;

	Snake_NewFood();

	for (int i = 0; i < sizeof(SnakeBD) / sizeof(SnakeBody); ++i) {
		SnakeBD[i].x = SnakeBD[i].y = -1;
	}

	SnakeBodySize = 15;

}