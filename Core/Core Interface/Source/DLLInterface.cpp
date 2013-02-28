//===============================================================
// File:	DLLInterface.cpp
// Purpose: Handle DLL Interfacing
//===============================================================
#include "DLLInterface.h"
using namespace Engine;

//---------------------------------------------------------------
CoreDLL::CoreDLL()
{
	m_pCore	= nullptr;
	m_hDLL	= NULL;
}

//---------------------------------------------------------------
CoreDLL::~CoreDLL()
{
	// TODO:: Error Wasnt Shutdown
}

//---------------------------------------------------------------
void CoreDLL::Create(Core** _pCore)
{
	// Load DLL
	m_hDLL = LoadLibraryEx(L"Core.dll", NULL, 0);

	// Find Function & Call Function
	CREATECORE CreateRendererFunc = (CREATECORE)GetProcAddress(m_hDLL, "CreateCore");
	DWORD Err = GetLastError();

	CreateRendererFunc(m_hDLL, &m_pCore);
	(*_pCore) = m_pCore;
}

//---------------------------------------------------------------
void CoreDLL::Release()
{
	// Find Function & Call Function
	RELEASECORE ReleaseRendererFunc = (RELEASECORE)GetProcAddress(m_hDLL, "ReleaseCore");
	ReleaseRendererFunc(&m_pCore);
	m_pCore = nullptr;

	// Unload DLL
	FreeLibrary(m_hDLL);
	m_hDLL = NULL;
}
