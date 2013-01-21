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
		Renderer*	m_pRenderer;
		HMODULE		m_hDLL;

	public:
		RendererDLL();
		~RendererDLL();

		Renderer*	GetRenderer();
		HMODULE	GetModule();

		void CreateRenderer();
		void Release();
	};
}

#include "DLLInterface.inl"