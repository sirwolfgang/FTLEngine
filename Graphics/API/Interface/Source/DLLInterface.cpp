//===============================================================
// File:	DLLInterface.cpp
// Purpose: Handle DLL Interfacing
//===============================================================
#include "DLLInterface.h"
using namespace Graphics;

//---------------------------------------------------------------
RendererDLL::RendererDLL()
{
	m_pRenderer		= nullptr;
	m_hDLL			= NULL;
}

//---------------------------------------------------------------
RendererDLL::~RendererDLL()
{
	// TODO:: Error Wasnt Shutdown
}

//---------------------------------------------------------------
void RendererDLL::Create(Renderer** _pRenderer)
{
	// Load DLL
	m_hDLL = LoadLibraryEx(L"DirectX 11.0.dll", NULL, 0);

	// Find Function & Call Function
	CREATERENDERER CreateRendererFunc = (CREATERENDERER)GetProcAddress(m_hDLL, "CreateRenderer");
	DWORD Err = GetLastError();

	CreateRendererFunc(m_hDLL, &m_pRenderer);
	(*_pRenderer) = m_pRenderer;
}

//---------------------------------------------------------------
void RendererDLL::Release()
{
	// Find Function & Call Function
	RELEASERENDERER ReleaseRendererFunc = (RELEASERENDERER)GetProcAddress(m_hDLL, "ReleaseRenderer");
	ReleaseRendererFunc(&m_pRenderer);
	m_pRenderer = nullptr;

	// Unload DLL
	FreeLibrary(m_hDLL);
	m_hDLL = NULL;
}
