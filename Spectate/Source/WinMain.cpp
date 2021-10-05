#include<windows.h>

#define HInstance() GetModuleHandle(NULL)

WCHAR WindowsClassName[256];
WCHAR WindowsTitle[256];	

INT WindowWidth;
INT WindowHeight;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) 
{
	wcscpy_s(WindowsClassName,TEXT("Specter"));
	wcscpy_s(WindowsTitle,TEXT("Specter"));

	WindowWidth=1280;
	WindowHeight=720;

	#pragma region CreateWindow

	WNDCLASSEX _window;

	_window.cbSize = sizeof(WNDCLASSEX);
	_window.style=CS_HREDRAW|CS_VREDRAW;
	_window.cbClsExtra = 0;
	_window.cbWndExtra = 0;

	_window.hCursor = LoadCursor(nullptr, IDC_ARROW);
	_window.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	_window.hIcon = LoadIcon(0,IDI_APPLICATION);
	_window.hIconSm = LoadIcon(0,IDI_APPLICATION);

	_window.lpszClassName = WindowsClassName;
	_window.lpszMenuName = nullptr;

	_window.hInstance = HInstance();

	_window.lpfnWndProc = DefWindowProc;

	RegisterClassEx(&_window);

	#pragma endregion

	#pragma region DisplayWindow

	HWND hWnd = CreateWindow(WindowsClassName, WindowsTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd)
	{
		MessageBox(0,L"Failed to create a window",0,0);
		return 0;
	}
	ShowWindow(hWnd, SW_SHOW);
	#pragma endregion

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}

