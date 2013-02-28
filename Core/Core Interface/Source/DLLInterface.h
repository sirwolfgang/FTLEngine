//===============================================================
// File:	DLLInterface.h
// Purpose: Handle DLL Interfacing
//===============================================================
#pragma once
#include "Core.h"

namespace Engine
{
	class CoreDLL
	{
		Core*		m_pCore;
		HMODULE		m_hDLL;

	public:
		CoreDLL();
		~CoreDLL();

		Core*	GetCore();
		HMODULE	GetModule();

		void Create(Core** _pCore);
		void Release();
	};
}

#include "DLLInterface.inl"