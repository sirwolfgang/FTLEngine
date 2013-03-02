//===============================================================
// File:	Window.h
// Purpose: To handle window managment
//===============================================================
#pragma once
#include "Preprocessor.h"
#include "DataTypes.h"

namespace Platform
{
	class Window
	{
	public:
		enum eWINDOW_MODE
		{
			eWindow_Mode_Unspecified,
			eWindow_Mode_Normal,
			eWindow_Mode_Frameless_Fixed,
		};
	private:

		HWND		m_hWnd;
		HINSTANCE	m_hInstance;
		int32		m_nCmdShow;
		MSG			m_msg;

	public:
		Window();
		Window(Window const& _That);
		~Window();

		Window& operator=(Window const& _That);

		void Initialize(HINSTANCE _hInstance, int32 _nCmdShow);
		void Create(eWINDOW_MODE _eMode, utf16* _szTitle, int32 _nPosX, int32 _nPosY, int32 _nWidth, int32 _nHeight);
		void Destroy();
		void Show(int32 _nCmdShow);
		bool Update();
		HWND GetHandle();
	};
}

LRESULT CALLBACK WindowProc(HWND _hWnd, UINT _Message, WPARAM _wParam, LPARAM _lParam);

#include "Window.inl"