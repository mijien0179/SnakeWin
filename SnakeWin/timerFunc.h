#pragma once
#include "data.h"
#include <Windows.h>


#ifndef __TIMER_FUNCTION_H__
#define __TIMER_FUNCTION_H__

// Program Timer Callback Function Parameter
#define CALLBACK_PARAM (HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)

// Calculate Function
void CALLBACK Snake_CalculateFunction CALLBACK_PARAM;
void Snake_NewFood();


#endif