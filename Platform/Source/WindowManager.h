//===============================================================
// File:	WindowManager.h
// Purpose: To handle window managment
//===============================================================
#pragma once
#include "DLL.h"
#include "Preprocessor.h"
#include "DataTypes.h"

namespace Platform
{
	class PLATFORM_API WindowManager
	{
	public:
		enum WINDOW_MODE
		{
			WINDOW_MODE_NORMAL,
			WINDOW_MODE_FRAMELESS_FIXED,
		};
	private:

#ifdef PLATFORM_WINDOWS
		HWND		m_hWnd;
		HINSTANCE	m_hInstance;
		int32		m_nCmdShow;
		MSG			m_msg;

		WindowManager();
	public:
		WindowManager(HINSTANCE _hInstance, int32 _nCmdShow);
#endif

		~WindowManager();

		void Create(WINDOW_MODE _eMode, utf16* _szTitle, int32 _nPosX, int32 _nPosY, int32 _nWidth, int32 _nHeight);
		void Destroy();
		void Show();
		void Hide();
		void Minimize();
		void Maximize();
		bool Update();
	};

}

#ifdef PLATFORM_WINDOWS
LRESULT CALLBACK WindowProc(HWND _hWnd, UINT _Message, WPARAM _wParam, LPARAM _lParam);
#endif