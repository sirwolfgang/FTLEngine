//===============================================================
// File:	DLLInterface.h
// Purpose: Handle DLL Interfacing
//===============================================================
#pragma once
#include "Core.h"

namespace Core
{
	class CoreDLL
	{
		CoreInterface*		m_pCoreInterface;
		HMODULE				m_hDLL;

	public:
		CoreDLL();
		~CoreDLL();

		CoreInterface*	GetCoreInterface();
		HMODULE			GetModule();

		void Create(CoreInterface** _pCore);
		void Release();
	};
}

#include "DLLInterface.inl"