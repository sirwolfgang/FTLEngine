//===============================================================
// File:	Renderer.h
// Purpose: Act as the direct Rendering Interface
//===============================================================
#pragma once
#include "DLL.h"
#include <FTLCore.h>

namespace Graphics
{
	class GRAPHICS_API Renderer
	{
		ID3D11Device*			m_pDevice;
		ID3D11DeviceContext*	m_pDeviceContext;
		IDXGISwapChain*			m_pSwapChain;

	public:
		Renderer();
		~Renderer();
	};
}

// TODO::
// User Facing Settings:
// * Resolution Width
// * Resolution Height
// * RefeshRate
// * RefeshRate
// * Multisamples Per Pixel(MSAA)
// * Quality Level
// * Buffer Count
// * Windowed Mode
// * Video Adapter
// * Driver Mode
// Passed Parameters:
// + Handle To Output Window
// + Flags[Debuggable]