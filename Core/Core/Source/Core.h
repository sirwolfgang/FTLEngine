//===============================================================
// File:	Core.h
// Purpose: Act as the class and interface for the DLL
//===============================================================
#pragma once
#include <FTLCore.h>

namespace Engine
{
	//---------------------------------------------------------------
	// DLL Component
	//---------------------------------------------------------------
	class Core_Library : public Core
	{
	public:
		Core_Library();
		virtual ~Core_Library();
	};


	//---------------------------------------------------------------
	// DLL Interfacing
	//---------------------------------------------------------------
	// Note: This code is not required(As its already included from
	//		the interface lub, but acts as a reminder to the 
	//		implementations found in the cpp.
	// extern "C"
	// {
	// 	void __declspec(dllimport) CreateCore(HINSTANCE _hDLL, Core** _pInterface);
	// 	typedef void (*CREATECORE)(HINSTANCE _hDLL, Core** _pInterface);
	// 
	// 	void __declspec(dllimport) ReleaseCore(Core** _pInterface);
	// 	typedef void (*RELEASECORE)(Core** pInterface);
	// }
}