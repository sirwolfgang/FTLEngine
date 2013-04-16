//===============================================================
// File:	DLLInterface.h
// Purpose: Handle DLL Interfacing
//===============================================================
#pragma once
#include "Renderer.h"

namespace Graphics
{
	class RendererDLL
	{
		IRenderer*	m_pRenderer;
		HMODULE		m_hDLL;

	public:
		RendererDLL();
		~RendererDLL();

		IRenderer*	GetRenderer();
		HMODULE		GetModule();

		void Create(IRenderer** _pRenderer);
		void Release();
	};
}

#include "DLLInterface.inl"