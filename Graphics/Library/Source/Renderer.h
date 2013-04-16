//===============================================================
// File:	Renderer.h
// Purpose: Act as the direct Rendering Interface
//===============================================================
#pragma once
#include <FTLGraphics.h>

namespace Graphics
{
	class Renderer : public IRenderer
	{
	public:
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
		virtual void Present()							= 0;

		virtual void Draw(uint32 _nVertexCount, uint32 _nFirstVertex)						= 0;
		virtual void Draw(uint32 _nIndexCount, uint32 _nFirstIndex, uint32 _nFirstVertex)	= 0;

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

		virtual HVertexBuffer	CreateVertexBuffer(uint32 _nVertices, void* _pData, HVertexFormat _hFormat)		= 0;
		virtual void			SetVertexBufferActive(HVertexBuffer _hVertexBuffer)								= 0;

		virtual HIndexBuffer	CreateIndexBuffer(uint32 _nIndices, uint32 _pData[])	= 0;
		virtual void			SetIndexBufferActive(HIndexBuffer _hIndexBuffer)		= 0;

		virtual HConstantBuffer CreateConstantBuffer(uint32 _sizeOf_a16, void* _pData, Shader::eSHADER_TYPES _eShaderType)	= 0;
		virtual void			SetConstantBufferActive(HConstantBuffer _hConstantBuffer)									= 0;

		virtual void			UpdateBuffer(HBuffer _hBuffer, void* _pData) = 0;

		//---------------------------------------------------------------
		// View Management
		//---------------------------------------------------------------
		virtual bool IsFullscreen()						= 0;
		virtual void SetFullscreen(bool _bFullscreen)	= 0;
	};
}

#include "Renderer.inl"