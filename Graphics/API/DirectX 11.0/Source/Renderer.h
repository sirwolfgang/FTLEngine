//===============================================================
// File:	Renderer.h
// Purpose: Act as the direct Rendering Interface
//===============================================================
#pragma once
#include <FTLGraphicsLibrary.h>
#include "DirectX.h"
#include "Shader.h"
#include "Buffer.h"
#include "VertexFormat.h"
#include "Primitive.h"
#include "InputLayout.h"

namespace Graphics
{
	class Renderer_DX11_0 : public Renderer
	{
		// Instances
		static Renderer_DX11_0*		sm_pInstance;

		// Settings
		Settings					m_tStarupSettings;
		bool						m_bIsFullscreen;

		// D3D
		ID3D11Device*				m_pDevice;
		ID3D11DeviceContext*		m_pDeviceContext;
		IDXGISwapChain*				m_pSwapChain;

		// Utility
		Platform::HandleManager				m_HandleManager;
		map<uint32, InputLayout_DX11_0*>	m_InputLayouts;

		// Memory
		vector<HShader>				m_hShaders;
		vector<HBuffer>				m_hBuffers;
		vector<HVertexFormat>		m_hVertexFormats;

		// Shaders
		ComputeShader_DX11_0*		m_pActiveComputeShader;
		DomainShader_DX11_0*		m_pActiveDomainShader;
		GeometryShader_DX11_0*		m_pActiveGeometryShader;
		HullShader_DX11_0*			m_pActiveHullShader;
		PixelShader_DX11_0*			m_pActivePixelShader;
		VertexShader_DX11_0*		m_pActiveVertexShader;

		// Layouts/Formats
		VertexFormat_DX11_0*		m_pActiveVertexFormat;
		InputLayout_DX11_0*			m_pActiveInputLayout;

		Primitive::eTOPOLOGY		m_eActivePrimitiveTopology;

		// Buffers
		VertexBuffer_DX11_0*		m_pActiveVertexBuffer;
		IndexBuffer_DX11_0*			m_pActiveIndexBuffer;

		ID3D11RenderTargetView*		m_pBackBuffer;

		void SetInputLayout();

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
		virtual void Present();

		virtual void Draw(uint32 _nVertexCount, uint32 _nFirstVertex);
		virtual void Draw(uint32 _nIndexCount, uint32 _nFirstIndex, uint32 _nFirstVertex);

		//---------------------------------------------------------------
		// Primitive Management
		//---------------------------------------------------------------
		virtual void					SetPrimitiveTopology(Primitive::eTOPOLOGY _eTopology);
		virtual Primitive::eTOPOLOGY	GetPrimitiveTopology();

		//---------------------------------------------------------------
		// Shader Management
		//---------------------------------------------------------------
		virtual HShader CompileFromFile(utf16* _szFile, utf8* _szFunction, Shader::eSHADER_TYPES _eShaderType);
		virtual void	SetShaderActive(HShader _hShader);
		void			SetShaderActive(Shader* _pShader);

		//---------------------------------------------------------------
		// Buffer Management
		//---------------------------------------------------------------
		virtual HVertexFormat	CreateVertexFormat(VertexFormat::VertDataPair _VertexFormatArray[], uint32 _nElements);
		void					SetVertexFormatActive(VertexFormat_DX11_0* _pVertexFormat);

		virtual HVertexBuffer	CreateVertexBuffer(uint32 _nVertices, void* _pData, HVertexFormat _hFormat);
		virtual void			SetVertexBufferActive(HVertexBuffer _hVertexBuffer);
		void					SetVertexBufferActive(VertexBuffer_DX11_0* _pVertexBuffer);

		virtual HIndexBuffer	CreateIndexBuffer(uint32 _nIndices, uint32 _pData[]);
		virtual void			SetIndexBufferActive(HIndexBuffer _hIndexBuffer);
		void					SetIndexBufferActive(IndexBuffer_DX11_0* _pIndexBuffer);

		virtual HConstantBuffer CreateConstantBuffer(uint32 _sizeOf_a16, void* _pData, Shader::eSHADER_TYPES _eShaderType);
		virtual void			SetConstantBufferActive(HConstantBuffer _hConstantBuffer);
		void					SetConstantBufferActive(ConstantBuffer_DX11_0* _pConstantBuffer);

		virtual void			UpdateBuffer(HBuffer _hBuffer, void* _pData);
		void					UpdateBuffer(BaseBuffer_DX11_0* _pBuffer, void* _pData);

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