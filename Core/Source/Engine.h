//===============================================================
// File:	Engine.h
// Purpose: To handle game engine runtime, and scope
//===============================================================
#pragma once
#include <FTLPlatform.h>
#include "DLL.h"
#include "Module\ModuleManager.h"

namespace Core
{
	class CORE_API Engine
	{
		static Engine*	sm_Instance;

		Engine();
	public:
		Engine(HINSTANCE _hInstance, LPSTR _lpCmdLine, int _nCmdShow);
		~Engine();

		int32 Run();

		static Engine* Global();
	private:
		// Engine/Global Scoped Variables
		HINSTANCE	m_hInstance;
		LPSTR		m_lpCmdLine;
		int32		m_nCmdShow;
	public:
		HINSTANCE	hInstance();
		LPSTR		lpCmdLine();
		int32		nCmdShow();
	};
};

#include "Engine.inl"