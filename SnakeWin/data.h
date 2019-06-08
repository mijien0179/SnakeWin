#pragma once

#ifndef __HEADER_DATA_H__
#define __HEADER_DATA_H__

#define SNAKE_BODY_SIZE (50)

typedef enum SnakeGameState {
	SGS_BEFORE = 0,
	SGS_GAME = 1,
	SGS_ENDED = -1
}SGS;

typedef enum TimerEventCode {
	TEC_CALCULATE = 1
}SnakeTEC;

typedef struct MAPPED_FUNCTION {
	int eventCode;
	void (*func)(HWND, UINT, WPARAM, LPARAM);
}MFC;

typedef struct PAINT_MAPPED_FUNCTION {
	SGS eventCode;
	void (*func)(HDC , HWND , UINT, WPARAM , LPARAM );
}PMFC;

typedef struct KEYBOARD_MAPPED_FUNCTION {
	SGS eventCode;
	void (*func)(HWND, UINT, WPARAM, LPARAM);
}KBMFC;

struct Point {
	short x;
	short y;
};

typedef struct Point SnakeBody;
typedef struct Point Food;

extern int SnakeDirection;
extern const int RefreshTime;
extern const int SNAKE_MAP_SIZE;

extern int StartX;
extern int StartY;

extern SGS Game_State;

extern const int MapPadding;
extern int SnakeBodySize;

extern Food FoodPosition;

extern SnakeBody SnakeBD[SNAKE_BODY_SIZE];

#endif