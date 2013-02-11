//===============================================================
// File:	Renderer.h
// Purpose: Act as the direct Rendering Interface
//===============================================================
#pragma once
#include <FTLPlatform.h>
#include "Shader.h"
#include "Buffer.h"
#include "VertexFormat.h"
#include "Primitive.h"
using Platform::Handle;

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
		virtual void ClearBackBuffer(float _fRGBA[4])	= 0; 
		virtual void PreDraw()							= 0;
		virtual void PostDraw()							= 0;
		virtual void Present()							= 0;

		virtual void Draw(uint32 _nVertexCount, uint32 _nFirstVertex) = 0;

		//---------------------------------------------------------------
		// Primitive Management
		//---------------------------------------------------------------
		virtual void					SetPrimitiveTopology(Primitive::eTOPOLOGY _eTopology)	= 0;
		virtual Primitive::eTOPOLOGY	GetPrimitiveTopology()									= 0;

		//---------------------------------------------------------------
		// Shader Management
		//---------------------------------------------------------------
		virtual HShader CompileFromFile(utf16* _szFile, utf8* _szFunction, Shader::eSHADER_TYPES _eShaderType)	= 0;
		virtual void	SetShaderActive(HShader _hShader)	= 0;

		//---------------------------------------------------------------
		// Buffer Management
		//---------------------------------------------------------------
		virtual HVertexFormat	CreateVertexFormat(VertexFormat::VertDataPair _VertexFormatArray[], uint32 _nElements)	= 0;
		virtual HVertexBuffer	CreateVertexBuffer(uint32 _nVertices, void* _pData, HVertexFormat _hFormat)				= 0;
		virtual void			SetVertexBufferActive(HVertexBuffer _hVertexBuffer)										= 0;

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