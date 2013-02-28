//===============================================================
// File:	Component.h
// Purpose: Act as the base class and interface for the DLL
//===============================================================
#pragma once
#include <Windows.h>

namespace Engine
{
	class Core
	{
	public:
		virtual ~Core(){}
	};

	//---------------------------------------------------------------
	// DLL Interfacing
	//---------------------------------------------------------------
	extern "C"
	{
		void __declspec(dllimport) CreateCore(HINSTANCE _hDLL, Core** _pInterface);
		typedef void (*CREATECORE)(HINSTANCE _hDLL, Core** _pInterface);

		void __declspec(dllimport) ReleaseCore(Core** _pInterface);
		typedef void (*RELEASECORE)(Core** pInterface);
	}
}