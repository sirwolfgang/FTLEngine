//===============================================================
// File:	Window.cpp
// Purpose: To handle window managment
//===============================================================
#include "Window.h"
#include "Assert.h"
using namespace Platform;

//---------------------------------------------------------------
Window::Window()
{
	m_hWnd		= NULL;
	m_hInstance = NULL;
	m_nCmdShow	= NULL;
}

//---------------------------------------------------------------
Window::Window(Window const& _That)
{
	*this = _That;
}

//---------------------------------------------------------------
Window::~Window()
{
	if(m_hWnd)
		Destroy();

	if(m_hWnd || m_hInstance || m_nCmdShow)
	{
		UnregisterClass(L"FTLWindowClass", m_hInstance);
		assert(GetLastError() == 0);
	}
}

//---------------------------------------------------------------
Window& Window::operator=(Window const& _That)
{
	m_hWnd		= _That.m_hWnd;
	m_hInstance	= _That.m_hInstance;
	m_nCmdShow	= _That.m_nCmdShow;
	m_msg		= _That.m_msg;

	return *this;
}

//---------------------------------------------------------------
void Window::Initialize(HINSTANCE _hInstance, int32 _nCmdShow)
{
	m_hWnd		= NULL;
	m_hInstance = _hInstance;
	m_nCmdShow	= _nCmdShow;

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize			= sizeof(WNDCLASSEX);
	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= WindowProc;
	wc.hInstance		= _hInstance;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	//wc.hbrBackground	= (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName	= L"FTLWindowClass";

	RegisterClassEx(&wc);
	assert(GetLastError() == 0);
}

//---------------------------------------------------------------
void Window::Create(eWINDOW_MODE _eMode, utf16* _szTitle, int32 _nPosX, int32 _nPosY, int32 _nWidth, int32 _nHeight)
{
	if(m_hWnd)
		Destroy();

	DWORD windowStyle = (_eMode == eWindow_Mode_Normal) ? WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX : WS_POPUP;

	// Adjust Window to be true res size on with client window
	RECT windowRect = {0, 0, _nWidth, _nHeight};
	AdjustWindowRectEx(&windowRect, windowStyle, false, NULL);
	assert(GetLastError() == 0);

	m_hWnd = CreateWindowEx(NULL,
		L"FTLWindowClass",					// Name of the window class
		_szTitle,							// Title
		windowStyle,						// Style
		_nPosX,								// X position
		_nPosY,								// Y position
		windowRect.right - windowRect.left,	// Width
		windowRect.bottom - windowRect.top,	// Height
		NULL,								// Parent Window
		NULL,								// Menus
		m_hInstance,						// Application handle
		NULL);								// Multiple windows
	assert(GetLastError() == 0);

	ShowWindow(m_hWnd, m_nCmdShow);
	assert(GetLastError() == 0);
}

//---------------------------------------------------------------
void Window::Destroy()
{
	if(DestroyWindow(m_hWnd))
	{
		m_hWnd = NULL;
		assert(GetLastError() == 0);
	}
}

//---------------------------------------------------------------
void Window::Show(int32 _nCmdShow)
{
	ShowWindow(m_hWnd, _nCmdShow);
	assert(GetLastError() == 0);
}

//---------------------------------------------------------------
bool Window::Update()
{
	// TODO:: Proper Windows Error Handling
	if(PeekMessage(&m_msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&m_msg);
		DispatchMessage(&m_msg);

		return (m_msg.message != WM_QUIT);
	}
	return true;
}

//---------------------------------------------------------------
LRESULT CALLBACK WindowProc(HWND _hWnd, UINT _Message, WPARAM _wParam, LPARAM _lParam)
{
	// TODO: Handle Windows Events, By dispatching them to engine

	switch(_Message)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		} break;
	}

	return DefWindowProc(_hWnd, _Message, _wParam, _lParam);
}
