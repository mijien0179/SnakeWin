#include <Windows.h>
#include "data.h"
#pragma once

#ifndef __PAINT_FUNCTION_H__
#define __PAINT_FUNCTION_H__

#define PAINT_PARAMETER (HDC hdc, HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)

extern const PMFC paintEventList[];
extern const int sPaintEventList;

void PaintGameBefore PAINT_PARAMETER;
void PaintGame PAINT_PARAMETER;
void PaintGameEnd PAINT_PARAMETER;
#endif