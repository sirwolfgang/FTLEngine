//===============================================================
// File:	Renderer.h
// Purpose: Act as the direct Rendering Interface
//===============================================================
#pragma once
#include <FTLGraphics.h>
#include "DLL.h"
#include "DirectX.h"
#include "Shader.h"
#include "VertexBuffer.h"

namespace Graphics
{
	class Renderer_DX11_0 : public Renderer
	{
		static Renderer_DX11_0* sm_pInstance;

		Settings				m_StarupSettings;

		ID3D11Device*			m_pDevice;
		ID3D11DeviceContext*	m_pDeviceContext;
		IDXGISwapChain*			m_pSwapChain;

		ID3D11RenderTargetView* m_pBackBuffer;

		bool					m_bIsFullscreen;

	public:
		//---------------------------------------------------------------
		// Singleton
		//---------------------------------------------------------------
		static Renderer_DX11_0* Instance();

		//---------------------------------------------------------------
		// Class Construction
		//---------------------------------------------------------------
		Renderer_DX11_0();
		virtual ~Renderer_DX11_0();

		//---------------------------------------------------------------
		// Rendering System Managment
		//---------------------------------------------------------------
		virtual void Initialize(Settings _tSettings);
		virtual void Startup();
		virtual void Shutdown();
		virtual void Restart();

		//---------------------------------------------------------------
		// Device Access
		//---------------------------------------------------------------
		ID3D11Device*			Device();
		ID3D11DeviceContext*	DeviceContext();

		//---------------------------------------------------------------
		// Rendering Settings
		//---------------------------------------------------------------
		virtual uint32		GetWidth();
		virtual uint32		GetHeight();
		virtual uint32		GetRefreshRate();
		virtual uint32		GetMSAASamples();
		virtual uint32		GetSampleQuality();
		virtual uint32		GetBuffersCount();
		virtual eDriverMode GetDriverMode();
		virtual bool		GetDebugMode();

		//---------------------------------------------------------------
		// Draw Management
		//---------------------------------------------------------------
		virtual void ClearBackBuffer(float _fRGBA[4]);
		virtual void PreDraw();
		virtual void PostDraw();
		virtual void Present();

		//---------------------------------------------------------------
		// Shader Management
		//---------------------------------------------------------------
		virtual Shader* CompileFromFile(utf16* _szFile, utf8* _szFunction, Shader::eSHADER_TYPES _eShaderType);

		//---------------------------------------------------------------
		// Buffer Management
		//---------------------------------------------------------------
		virtual VertexFormat* CreateVertexFormat(VertexFormat::VertDataPair _VertexFormatArray[], uint32 _nLength);
		virtual VertexBuffer* CreateVertexBuffer(uint32 _nBufferSize, void* _pData, VertexFormat* _pFormat);

		//---------------------------------------------------------------
		// View Management
		//---------------------------------------------------------------
		virtual bool IsFullscreen();
		virtual void SetFullscreen(bool _bFullscreen);
	};

	//---------------------------------------------------------------
	// DLL Interfacing
	//---------------------------------------------------------------
	// Note: This code is not required, but acts as a reminder to the
	//	implementations found in the cpp.
	// extern "C"
	// {
	// 	void DLLEXPORT CreateRenderer(HINSTANCE _hDLL, Renderer** _pInterface);
	// 	typedef void (*CREATERENDERER)(HINSTANCE _hDLL, Renderer** _pInterface);
	// 
	// 	void DLLEXPORT ReleaseRenderer(Renderer** _pInterface);
	// 	typedef void (*RELEASERENDERER)(Renderer** pInterface);
	// }
}

#include "Renderer.inl"