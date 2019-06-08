#include "paintFunc.h"
#include <stdio.h>

const PMFC paintEventList[] = {
	 {SGS_BEFORE, PaintGameBefore}
	,{SGS_GAME, PaintGame}
	,{SGS_ENDED, PaintGameEnd}
};
const int sPaintEventList = sizeof(paintEventList);

void PaintGameBefore PAINT_PARAMETER
{
	char* str = "If you want play the game, Press the Arrow key...";
	TextOut(hdc, 10,10, str, strlen(str));
}

void PaintGame PAINT_PARAMETER
{
	RECT rect;
	GetClientRect(hWnd, &rect);
	
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	int min = width < height ? width : height;
	min -= 70;
	min -= min % SNAKE_MAP_SIZE;

	int startX, startY;
	int singleSize = min / SNAKE_MAP_SIZE;
	startX = width / 2 - min / 2 - singleSize/2;
	startY = height / 2 - min / 2 - singleSize/2;
	
	for (int y = 0; y < SNAKE_MAP_SIZE; ++y) {
		for (int x = 0; x < SNAKE_MAP_SIZE; ++x) {
			Rectangle(hdc, startX + x * singleSize, startY + y * singleSize,
				startX + (x+1) * singleSize, startY + (y+1) * singleSize);
		}
	}
	HBRUSH oldPen = SelectObject(hdc, GetStockObject(GRAY_BRUSH));

	for(int i = 1; i < SNAKE_MAP_SIZE && i < SnakeBodySize; ++i) {
		if (SnakeBD[i].x < 0 || SnakeBD[i].y < 0) continue;
		Rectangle(hdc, startX + SnakeBD[i].x * singleSize, startY + SnakeBD[i].y * singleSize,
			startX + (SnakeBD[i].x + 1) * singleSize, startY + (SnakeBD[i].y + 1) * singleSize);
	}
	SelectObject(hdc, GetStockObject(BLACK_BRUSH));

	Rectangle(hdc, startX + SnakeBD[0].x * singleSize, startY + SnakeBD[0].y * singleSize,
		startX + (SnakeBD[0].x + 1) * singleSize, startY + (SnakeBD[0].y + 1) * singleSize);

	SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));

	Rectangle(hdc, startX + FoodPosition.x * singleSize, startY + FoodPosition.y * singleSize,
		startX + (FoodPosition.x + 1) * singleSize, startY + (FoodPosition.y + 1) * singleSize);
	
	oldPen = SelectObject(hdc, oldPen);

	DeleteObject(oldPen);

}

void PaintGameEnd PAINT_PARAMETER
{
	RECT rect;
	GetClientRect(hWnd, &rect);
	int width, height;
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;
	SetTextAlign(hdc, TA_CENTER);
	char* str = "GameOver. If You want to retry, Press R";

	TextOut(hdc, width / 2, height/2, str, strlen(str));
}