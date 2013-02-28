//===============================================================
// File:	DLLInterface.cpp
// Purpose: Handle DLL Interfacing
//===============================================================
#include "DLLInterface.h"
using namespace Core;

//---------------------------------------------------------------
CoreDLL::CoreDLL()
{
	m_pCoreInterface	= nullptr;
	m_hDLL				= NULL;
}

//---------------------------------------------------------------
CoreDLL::~CoreDLL()
{
	// TODO:: Error Wasnt Shutdown
}

//---------------------------------------------------------------
void CoreDLL::Create(CoreInterface** _pCoreInterface)
{
	// Load DLL
	m_hDLL = LoadLibraryEx(L"Core.dll", NULL, 0);

	// Find Function & Call Function
	CREATECOREINTERFACE CreateCoreInterface = (CREATECOREINTERFACE)GetProcAddress(m_hDLL, "CreateCoreInterface");
	DWORD Err = GetLastError();

	CreateCoreInterface(m_hDLL, &m_pCoreInterface);
	(*_pCoreInterface) = m_pCoreInterface;
}

//---------------------------------------------------------------
void CoreDLL::Release()
{
	// Find Function & Call Function
	RELEASECOREINTERFACE ReleaseCoreInterface = (RELEASECOREINTERFACE)GetProcAddress(m_hDLL, "ReleaseCoreInterface");
	ReleaseCoreInterface(&m_pCoreInterface);
	m_pCoreInterface = nullptr;

	// Unload DLL
	FreeLibrary(m_hDLL);
	m_hDLL = NULL;
}
