//===============================================================
// File:	Component.h
// Purpose: Act as the base class and interface for the DLL
//===============================================================
#pragma once
#include <FTLPlatform.h>
#include "Engine.h"

namespace Core
{
	class CoreInterface
	{
	public:
		virtual ~CoreInterface(){}

		virtual Engine* InitializeEngine(Engine::InitializationData& _InitializationData) = 0;
	};

	//---------------------------------------------------------------
	// DLL Interfacing
	//---------------------------------------------------------------
	extern "C"
	{
		void __declspec(dllimport) CreateCoreInterface(HINSTANCE _hDLL, CoreInterface** _pInterface);
		typedef void (*CREATECOREINTERFACE)(HINSTANCE _hDLL, CoreInterface** _pInterface);

		void __declspec(dllimport) ReleaseCoreInterface(CoreInterface** _pInterface);
		typedef void (*RELEASECOREINTERFACE)(CoreInterface** _pInterface);
	}
}

#include "DLLInterface.h"