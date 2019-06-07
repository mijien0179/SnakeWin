#include "data.h"
#include "paintFunc.h"
#include "InputFunc.h"

#include <Windows.h>
#pragma once

#ifndef __PROC_FUNCTION_H__
#define __PROC_FUNCTION_H__

// Windows Proc Message Callback Function Parameter
// #define PARAMETER (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)

extern const MFC procEventList[];
extern const sProcEventList;

#pragma region PAINT_FUNCTION
	void Snake_PaintFunction PARAMETER;
#pragma endregion

#pragma region KEYDOWN_FUNCTION
	void Snake_KeyDownFunction PARAMETER;
#pragma endregion

void Snake_CreateInitFunction PARAMETER;

#endif