#include "procFunc.h"
#include <stdio.h>



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	if (WM_DESTROY == message) {
		PostQuitMessage(0);
		return 0;
	}
	int count = sProcEventList / sizeof(MFC);

	for (int i = 0; i < count; ++i) {
		if (message == procEventList[i].eventCode) {
			procEventList[i].func(hWnd, message, wParam, lParam);

			return 0;
		}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASS wc;

	char* clsName = "SnakeWin";
	char* WinName = clsName;

	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = clsName;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	unsigned int ScreenX, ScreenY;
	ScreenX = GetSystemMetrics(SM_CXSCREEN);
	ScreenY = GetSystemMetrics(SM_CYSCREEN);
	unsigned int WindowWidth, WindowHeight;
	WindowWidth = 800;
	WindowHeight = 500;


	HWND hWnd = CreateWindow(clsName, WinName, WS_OVERLAPPEDWINDOW, ScreenX / 2 - WindowWidth / 2, ScreenY / 2 - WindowHeight / 2,
		WindowWidth, WindowHeight, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}