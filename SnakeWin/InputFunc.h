#include <Windows.h>
#include "data.h"
#include "timerFunc.h"
#pragma once

#ifndef __INPUT_FUNCTION_H__
#define __INPUT_FUNCTION_H__

// Windows Proc Message Callback Function Parameter
#define PARAMETER (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)


extern const KBMFC keydownEventList[];
extern const int sKeydownEventList;

void Keydown_Before PARAMETER;
void Keydown_Game PARAMETER;
void Keydown_Ended PARAMETER;
void Snake_GameInit();

#endif