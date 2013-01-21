//===============================================================
// File:	Renderer.h
// Purpose: Act as the direct Rendering Interface
//===============================================================
#pragma once
#include <FTLGraphics.h>
#include "DLL.h"

namespace Graphics
{
	class Renderer_DX11_0 : public Renderer
	{
	public:
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
		virtual void ClearBuffer(float _fARGB[4]);
		virtual void PreDraw();
		virtual void PostDraw();
		virtual void Present();

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