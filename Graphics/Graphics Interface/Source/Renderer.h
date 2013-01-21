//===============================================================
// File:	Renderer.h
// Purpose: Act as the direct Rendering Interface
//===============================================================
#pragma once
#include <FTLPlatform.h>

namespace Graphics
{
	class Renderer
	{
	public:
		enum eDriverMode
		{
			eDriverMode_Unspecified,// Error
			eDriverMode_Hardware,	// Normal Rendering
			eDriverMode_Software,	// Software Emulation
			eDriverMode_Reference,	// Precision Software Emulation, Rendering 
			eDriverMode_Null,		// Precision Software Emulation, No Rendering
		};

		struct Settings
		{
			// User Facing Settings:
			uint32			nWidth;			// * Resolution Width
			uint32			nHeight;		// * Resolution Height
			uint32			nRefreshRate;	// * RefeshRate [Express as RefreshRate / 1000], 0 - Vsync Off, -1 - Detect RefreshRate
			uint32 			nMSAASamples;	// * Multisamples Per Pixel(MSAA)
			uint32			nSampleQuality;	// * Quality Level
			uint32			nBufferCount;	// * Buffer Count
			eDriverMode		eDriverMode;	// * Driver Mode
			// Passed Parameters:
			HWND			hOutput;		// + Handle To Output Window
			bool			bDebugMode;		// + Flags[Debuggable]
		};

		//---------------------------------------------------------------
		// Class Destruction
		//---------------------------------------------------------------
		virtual ~Renderer()								= 0;

		//---------------------------------------------------------------
		// Rendering System Managment
		//---------------------------------------------------------------
		virtual void Initialize(Settings _tSettings)	= 0;
		virtual void Startup()							= 0;
		virtual void Shutdown()							= 0;
		virtual void Restart()							= 0;

		//---------------------------------------------------------------
		// Rendering Settings
		//---------------------------------------------------------------
		virtual uint32		GetWidth()					= 0;
		virtual uint32		GetHeight()					= 0;
		virtual uint32		GetRefreshRate()			= 0;
		virtual uint32		GetMSAASamples()			= 0;
		virtual uint32		GetSampleQuality()			= 0;
		virtual uint32		GetBuffersCount()			= 0;
		virtual eDriverMode GetDriverMode()				= 0;
		virtual bool		GetDebugMode()				= 0;

		//---------------------------------------------------------------
		// Draw Management
		//---------------------------------------------------------------
		virtual void ClearBuffer(float _fARGB[4])		= 0; 
		virtual void PreDraw()							= 0;
		virtual void PostDraw()							= 0;
		virtual void Present()							= 0;

		//---------------------------------------------------------------
		// View Management
		//---------------------------------------------------------------
		virtual bool IsFullscreen()						= 0;
		virtual void SetFullscreen(bool _bFullscreen)	= 0;
	};

	//---------------------------------------------------------------
	// DLL Interfacing
	//---------------------------------------------------------------
	extern "C"
	{
		void DLLIMPORT CreateRenderer(HINSTANCE _hDLL, Renderer** _pInterface);
		typedef void (*CREATERENDERER)(HINSTANCE _hDLL, Renderer** _pInterface);

		void DLLIMPORT ReleaseRenderer(Renderer** _pInterface);
		typedef void (*RELEASERENDERER)(Renderer** pInterface);
	}
}

#include "Renderer.inl"