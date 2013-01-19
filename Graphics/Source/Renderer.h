//===============================================================
// File:	Renderer.h
// Purpose: Act as the direct Rendering Interface
//===============================================================
#pragma once
#include "DLL.h"
#include "DirectX.h"
#include <FTLPlatform.h>

namespace Graphics
{
	class GRAPHICS_API Renderer
	{
	public:
		struct GRAPHICS_API Settings
		{
			HWND	hOutput;
			uint32	Width;
			uint32	Height;
			uint32	RefreshRate; // Express as RefreshRate / 1000

			Settings();
		};

	private:
		ID3D11Device*			m_pDevice;
		ID3D11DeviceContext*	m_pDeviceContext;
		IDXGISwapChain*			m_pSwapChain;

		ID3D11RenderTargetView* m_pBackBuffer;

		Renderer();
	public:
		Renderer(Settings& _Settings);
		~Renderer();

		void RenderFrame();
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