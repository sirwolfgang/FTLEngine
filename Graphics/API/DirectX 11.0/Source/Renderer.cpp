//===============================================================
// File:	Renderer.cpp
// Purpose: Act as the direct Rendering Interface
//===============================================================
#include "Renderer.h"
using namespace Graphics;

//---------------------------------------------------------------
// Singleton
//---------------------------------------------------------------
Renderer_DX11_0* Renderer_DX11_0::sm_pInstance = nullptr;

//---------------------------------------------------------------
void Renderer_DX11_0::SetInputLayout()
{
	if(m_pActiveInputLayout 
		|| !m_pActiveVertexShader 
		|| !m_pActiveVertexFormat)
		return;

	// TODO:: Check for collisions, 32/64 bit modes
	uint32 Hash = (((uint32)m_pActiveVertexShader & (0x0000FFFF)) << 16) + ((uint32)m_pActiveVertexFormat & (0x0000FFFF));

	m_pActiveInputLayout = m_InputLayouts[Hash];

	if(!m_pActiveInputLayout)
	{
		// Build Input Layout
		ID3D11InputLayout* pLayout;

		m_pDevice->CreateInputLayout(m_pActiveVertexFormat->GetVertexFormat(), 
			m_pActiveVertexFormat->GetNumberElements(), 
			m_pActiveVertexShader->GetBlob()->GetBufferPointer(), 
			m_pActiveVertexShader->GetBlob()->GetBufferSize(), 
			&pLayout);

		m_pActiveInputLayout = new InputLayout_DX11_0(pLayout);
		m_InputLayouts[Hash] = m_pActiveInputLayout;
	}

	m_pDeviceContext->IASetInputLayout(m_pActiveInputLayout->GetInputLayout());
}

//---------------------------------------------------------------
// Class Construction
//---------------------------------------------------------------
Renderer_DX11_0::Renderer_DX11_0() 
	: m_pDevice(nullptr), 
	m_pDeviceContext(nullptr), 
	m_pSwapChain(nullptr), 
	m_pBackBuffer(nullptr),
	m_HandleManager(),
	m_InputLayouts(),
	m_bIsFullscreen(false), 
	m_pActiveComputeShader(nullptr), 
	m_pActiveDomainShader(nullptr), 
	m_pActiveGeometryShader(nullptr), 
	m_pActiveHullShader(nullptr), 
	m_pActivePixelShader(nullptr), 
	m_pActiveVertexShader(nullptr),
	m_pActiveVertexFormat(nullptr),
	m_pActiveInputLayout(nullptr),
	m_pActiveVertexBuffer(nullptr),
	m_pActiveIndexBuffer(nullptr),
	m_eActivePrimitiveTopology(Primitive::eTOPOLOGY_UNDEFINED)
{
	sm_pInstance = this;
}

//---------------------------------------------------------------
Renderer_DX11_0::~Renderer_DX11_0()
{
	sm_pInstance = nullptr;

	// TODO:: Error Not Shutdown properly
	if(m_pDevice 
		|| m_pDeviceContext 
		|| m_pSwapChain 
		|| m_pBackBuffer)
	{
		Shutdown();
	}
}

//---------------------------------------------------------------
// Rendering System Managment
//---------------------------------------------------------------
void Renderer_DX11_0::Initialize(Settings _tSettings)
{
	m_tStarupSettings = _tSettings;
}

//---------------------------------------------------------------
void Renderer_DX11_0::Startup()
{
	DXGI_SWAP_CHAIN_DESC SwapChainDesc;
	ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	SwapChainDesc.BufferDesc.Width						= m_tStarupSettings.nWidth;					//* Resolution Width
	SwapChainDesc.BufferDesc.Height						= m_tStarupSettings.nHeight;				//* Resolution Height
	SwapChainDesc.BufferDesc.RefreshRate.Numerator		= m_tStarupSettings.nRefreshRate;			//* RefeshRate
	SwapChainDesc.BufferDesc.RefreshRate.Denominator	= 1000;										//* RefeshRate
	SwapChainDesc.BufferDesc.Format						= DXGI_FORMAT_R8G8B8A8_UNORM;				//  Format
	SwapChainDesc.BufferDesc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;		//  Scan Line Ordering
	SwapChainDesc.BufferDesc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;			//  Scaling Mode
	SwapChainDesc.SampleDesc.Count						= m_tStarupSettings.nMSAASamples;			//* Multisamples Per Pixel
	SwapChainDesc.SampleDesc.Quality					= m_tStarupSettings.nSampleQuality;			//* Quality Level
	SwapChainDesc.BufferUsage							= DXGI_USAGE_RENDER_TARGET_OUTPUT;			//  Buffer Usage
	SwapChainDesc.BufferCount							= m_tStarupSettings.nBufferCount;			//* Buffer Count
	SwapChainDesc.OutputWindow							= m_tStarupSettings.hOutput;				//+ Handle To Output Window
	SwapChainDesc.Windowed								= true;										//* Windowed Mode
	SwapChainDesc.SwapEffect							= DXGI_SWAP_EFFECT_DISCARD;					//  Swap Mode
	SwapChainDesc.Flags									= NULL;										// Flags

	m_bIsFullscreen		= false;

	//------------------------------
	D3D_DRIVER_TYPE DriverType;

	switch (m_tStarupSettings.eDriverMode)
	{
	case eDriverMode_Hardware:	{	DriverType = D3D_DRIVER_TYPE_HARDWARE;	}	break;
	case eDriverMode_Software:	{	DriverType = D3D_DRIVER_TYPE_SOFTWARE;	}	break;
	case eDriverMode_Reference: {	DriverType = D3D_DRIVER_TYPE_REFERENCE;	}	break;
	case eDriverMode_Null:		{	DriverType = D3D_DRIVER_TYPE_NULL;		}	break;
	case eDriverMode_Unspecified:
	default:					{	DriverType = D3D_DRIVER_TYPE_UNKNOWN;	}	break; // TODO:: Handle Error
	}

	HRESULT hResult = D3D11CreateDeviceAndSwapChain(NULL,
		DriverType,
		NULL,
		(m_tStarupSettings.eDriverMode) ? D3D11_CREATE_DEVICE_DEBUG : NULL,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&SwapChainDesc,
		&m_pSwapChain,
		&m_pDevice,
		nullptr,
		&m_pDeviceContext);

	//------------------------------
	ID3D11Texture2D *pBackBuffer;
	m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	m_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pBackBuffer);
	pBackBuffer->Release();

	m_pDeviceContext->OMSetRenderTargets(1, &m_pBackBuffer, NULL);

	//------------------------------
	D3D11_VIEWPORT Viewport;
	ZeroMemory(&Viewport, sizeof(D3D11_VIEWPORT));

	Viewport.TopLeftX	= 0;
	Viewport.TopLeftY	= 0;
	Viewport.Width		= (float)m_tStarupSettings.nWidth;
	Viewport.Height		= (float)m_tStarupSettings.nHeight;

	m_pDeviceContext->RSSetViewports(1, &Viewport);
}

//---------------------------------------------------------------
void Renderer_DX11_0::Shutdown()
{
	// Memory
	for(map<uint32, InputLayout_DX11_0*>::iterator Iterator = m_InputLayouts.begin(); Iterator != m_InputLayouts.end(); ++Iterator)
	{
		if(Iterator->second)
			delete Iterator->second;
	}
	m_InputLayouts.clear();

	for(memsize_s i = m_hShaders.size() - 1; i >= 0; --i)
	{
		delete m_hShaders[i].RetrieveEntry();
		m_HandleManager.RemoveEntry(m_hShaders[i]);
	}
	m_hShaders.clear();

	for(memsize_s i = m_hVertexFormats.size() - 1; i >= 0; --i)
	{
		delete m_hVertexFormats[i].RetrieveEntry();
		m_HandleManager.RemoveEntry(m_hVertexFormats[i]);
	}
	m_hVertexFormats.clear();

	for(memsize_s i = m_hVertexBuffers.size() - 1; i >= 0; --i)
	{
		delete m_hVertexBuffers[i].RetrieveEntry();
		m_HandleManager.RemoveEntry(m_hVertexBuffers[i]);
	}
	m_hVertexBuffers.clear();

	for(memsize_s i = m_hIndexBuffers.size() - 1; i >= 0; --i)
	{
		delete m_hIndexBuffers[i].RetrieveEntry();
		m_HandleManager.RemoveEntry(m_hIndexBuffers[i]);
	}
	m_hIndexBuffers.clear();

	for(memsize_s i = m_hConstantBuffers.size() - 1; i >= 0; --i)
	{
		delete m_hConstantBuffers[i].RetrieveEntry();
		m_HandleManager.RemoveEntry(m_hConstantBuffers[i]);
	}
	m_hConstantBuffers.clear();

	// Shaders
	m_pActiveComputeShader		= nullptr;
	m_pActiveDomainShader		= nullptr;
	m_pActiveGeometryShader		= nullptr;
	m_pActiveHullShader			= nullptr;
	m_pActivePixelShader		= nullptr;
	m_pActiveVertexShader		= nullptr;

	// Buffers
	m_pActiveVertexFormat		= nullptr;
	m_pActiveInputLayout		= nullptr;

	m_pActiveVertexBuffer		= nullptr;
	m_pActiveIndexBuffer		= nullptr;

	RELEASE_COM(m_pBackBuffer);


	if(m_pSwapChain)
	{
		m_pSwapChain->SetFullscreenState(false, NULL);
		m_bIsFullscreen = false;
	}

	RELEASE_COM(m_pSwapChain);
	RELEASE_COM(m_pDeviceContext);
	RELEASE_COM(m_pDevice);
}

//---------------------------------------------------------------
void Renderer_DX11_0::Restart()
{
	Shutdown();
	Startup();
}

//---------------------------------------------------------------
// Draw Management
//---------------------------------------------------------------
void Renderer_DX11_0::ClearBackBuffer(float _fARGB[4])
{
	m_pDeviceContext->ClearRenderTargetView(m_pBackBuffer, _fARGB);
}

//---------------------------------------------------------------
void Renderer_DX11_0::Present()
{
	m_pSwapChain->Present(0, 0);
}

//---------------------------------------------------------------
void Renderer_DX11_0::Draw(uint32 _nVertexCount, uint32 _nFirstVertex)
{
	SetInputLayout();
	m_pDeviceContext->Draw(_nVertexCount, _nFirstVertex);
}

//---------------------------------------------------------------
void Renderer_DX11_0::Draw(uint32 _nIndexCount, uint32 _nFirstIndex, uint32 _nFirstVertex)
{
	SetInputLayout();
	m_pDeviceContext->DrawIndexed(_nIndexCount, _nFirstIndex, _nFirstVertex);
}

//---------------------------------------------------------------
// Primitive Management
//---------------------------------------------------------------
void Renderer_DX11_0::SetPrimitiveTopology(Primitive::eTOPOLOGY _eTopology)
{
	m_pDeviceContext->IASetPrimitiveTopology(Primitive::Topology_DX11_0[_eTopology]);
}

//---------------------------------------------------------------
// Shader Management
//---------------------------------------------------------------
Handle<Shader> Renderer_DX11_0::CompileFromFile(utf16* _szFile, utf8* _szFunction, Shader::eSHADER_TYPES _eShaderType)
{
	ID3DBlob*	pCompiledCode	= nullptr;
	ID3DBlob*	pErrorMessage	= nullptr;
	void*		pShader			= nullptr;
	UINT		Flags1			= D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_OPTIMIZATION_LEVEL3 | D3DCOMPILE_WARNINGS_ARE_ERRORS;
	HShader		hShader;

	switch (_eShaderType)
	{
	case Shader::eSHADER_TYPE_COMPUTE:
		{
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "cs_5_0", Flags1, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateComputeShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11ComputeShader**) &pShader);
			hShader = m_HandleManager.CreateHandle((Shader*) new ComputeShader_DX11_0((ID3D11ComputeShader*)pShader, pCompiledCode));
		} break;
	case Shader::eSHADER_TYPE_DOMAIN:
		{
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "ds_5_0", Flags1, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateDomainShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11DomainShader**) &pShader);
			hShader = m_HandleManager.CreateHandle((Shader*) new DomainShader_DX11_0((ID3D11DomainShader*)pShader, pCompiledCode));
		} break;
	case Shader::eSHADER_TYPE_GEOMETRY:
		{ 
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "gs_5_0", Flags1, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateGeometryShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11GeometryShader**) &pShader);
			hShader = m_HandleManager.CreateHandle((Shader*) new GeometryShader_DX11_0((ID3D11GeometryShader*)pShader, pCompiledCode));
		} break;
	case Shader::eSHADER_TYPE_HULL:
		{ 		
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "hs_5_0", Flags1, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateHullShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11HullShader**) &pShader);
			hShader = m_HandleManager.CreateHandle((Shader*) new HullShader_DX11_0((ID3D11HullShader*)pShader, pCompiledCode));
		} break;
	case Shader::eSHADER_TYPE_PIXEL:
		{
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "ps_5_0", Flags1, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreatePixelShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11PixelShader**) &pShader);
			hShader = m_HandleManager.CreateHandle((Shader*) new PixelShader_DX11_0((ID3D11PixelShader*)pShader, pCompiledCode));
		} break;
	case Shader::eSHADER_TYPE_VERTEX:
		{ 
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "vs_5_0", Flags1, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateVertexShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11VertexShader**)&pShader);
			hShader = m_HandleManager.CreateHandle((Shader*) new VertexShader_DX11_0((ID3D11VertexShader*)pShader, pCompiledCode));
		} break;
	}

	m_hShaders.push_back(hShader);
	return hShader;
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetShaderActive(HShader _hShader)
{
	SetShaderActive(_hShader.RetrieveEntry());
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetShaderActive(Shader* _pShader)
{
	m_pActiveInputLayout = nullptr;

	switch(_pShader->GetShaderType())
	{
	case Shader::eSHADER_TYPE_COMPUTE:
		{
			m_pActiveComputeShader = (ComputeShader_DX11_0*)_pShader;
			m_pDeviceContext->CSSetShader((_pShader) ? ((ComputeShader_DX11_0*)_pShader)->GetShader() : nullptr, nullptr, NULL);
		} break;
	case Shader::eSHADER_TYPE_DOMAIN:
		{
			m_pActiveDomainShader = (DomainShader_DX11_0*)_pShader;
			m_pDeviceContext->DSSetShader((_pShader) ? ((DomainShader_DX11_0*)_pShader)->GetShader() : nullptr, nullptr, NULL);
		} break;
	case Shader::eSHADER_TYPE_GEOMETRY:
		{
			m_pActiveGeometryShader = (GeometryShader_DX11_0*)_pShader;
			m_pDeviceContext->GSSetShader((_pShader) ? ((GeometryShader_DX11_0*)_pShader)->GetShader() : nullptr, nullptr, NULL);
		} break;
	case Shader::eSHADER_TYPE_HULL:
		{
			m_pActiveHullShader = (HullShader_DX11_0*)_pShader;
			m_pDeviceContext->HSSetShader((_pShader) ? ((HullShader_DX11_0*)_pShader)->GetShader() : nullptr, nullptr, NULL);
		} break;
	case Shader::eSHADER_TYPE_PIXEL:
		{
			m_pActivePixelShader = (PixelShader_DX11_0*)_pShader;
			m_pDeviceContext->PSSetShader((_pShader) ? ((PixelShader_DX11_0*)_pShader)->GetShader() : nullptr, nullptr, NULL);
		} break;
	case Shader::eSHADER_TYPE_VERTEX:
		{
			m_pActiveVertexShader = (VertexShader_DX11_0*)_pShader;
			m_pDeviceContext->VSSetShader((_pShader) ? ((VertexShader_DX11_0*)_pShader)->GetShader() : nullptr, nullptr, NULL);
		} break;
	}
}

//---------------------------------------------------------------
// Buffer Management
//---------------------------------------------------------------
Handle<VertexFormat> Renderer_DX11_0::CreateVertexFormat(VertexFormat::VertDataPair _VertexFormatArray[], uint32 _nElements)
{
	HVertexFormat hVertexBuffer = m_HandleManager.CreateHandle((VertexFormat*)new VertexFormat_DX11_0(_VertexFormatArray, _nElements));
	m_hVertexFormats.push_back(hVertexBuffer);
	return hVertexBuffer;
}

//---------------------------------------------------------------
HVertexBuffer Renderer_DX11_0::CreateVertexBuffer(uint32 _nVertices, HVertexFormat _hFormat, void* _pData)
{
	HVertexBuffer hVertexBuffer;
	ID3D11Buffer* pVertexBuffer = nullptr;

	// Buffer Description
	D3D11_BUFFER_DESC BufferDescription;

	BufferDescription.Usage				= D3D11_USAGE_DEFAULT;
	BufferDescription.ByteWidth			= _nVertices * _hFormat->GetVertexSize();
	BufferDescription.BindFlags			= D3D11_BIND_VERTEX_BUFFER;
	BufferDescription.CPUAccessFlags	= NULL;
	BufferDescription.MiscFlags			= NULL;

	if(_pData)
	{
		// Subresource Data
		D3D11_SUBRESOURCE_DATA SubresourceData;

		SubresourceData.pSysMem				= _pData;
		SubresourceData.SysMemPitch			= NULL;
		SubresourceData.SysMemSlicePitch	= NULL; 

		// Create Buffer
		m_pDevice->CreateBuffer(&BufferDescription, &SubresourceData, &pVertexBuffer);
	}
	else
	{
		// Create Buffer
		m_pDevice->CreateBuffer(&BufferDescription, nullptr, &pVertexBuffer);
	}
	
	hVertexBuffer = m_HandleManager.CreateHandle((VertexBuffer*)new VertexBuffer_DX11_0(pVertexBuffer, (VertexFormat_DX11_0*)_hFormat.RetrieveEntry()));
	m_hVertexBuffers.push_back(hVertexBuffer);
	return hVertexBuffer;
}

//---------------------------------------------------------------
HIndexBuffer Renderer_DX11_0::CreateIndexBuffer(uint32 _nIndices, uint32 _pData[])
{
	HIndexBuffer hIndexBuffer;
	// Buffer Description
	D3D11_BUFFER_DESC BufferDescription;

	BufferDescription.Usage				= D3D11_USAGE_DEFAULT;
	BufferDescription.ByteWidth			= sizeof(uint32) * _nIndices;
	BufferDescription.BindFlags			= D3D11_BIND_INDEX_BUFFER;
	BufferDescription.CPUAccessFlags	= NULL;
	BufferDescription.MiscFlags			= NULL;

	// Subresource Data
	D3D11_SUBRESOURCE_DATA SubresourceData;

	SubresourceData.pSysMem				= _pData;
	SubresourceData.SysMemPitch			= NULL;
	SubresourceData.SysMemSlicePitch	= NULL; 

	// Create Buffer
	ID3D11Buffer* pIndexBuffer = nullptr;
	m_pDevice->CreateBuffer(&BufferDescription, &SubresourceData, &pIndexBuffer);

	hIndexBuffer = m_HandleManager.CreateHandle((IndexBuffer*)new IndexBuffer_DX11_0(pIndexBuffer));
	m_hIndexBuffers.push_back(hIndexBuffer);
	return hIndexBuffer;
}

//---------------------------------------------------------------
HConstantBuffer Renderer_DX11_0::CreateConstantBuffer(uint32 _sizeOf_a16, void* _pData, Shader::eSHADER_TYPES _eShaderType)
{
	// TODO:: Throw Error, SizeOf Must be 16 bytes aligned
	assert(_sizeOf_a16 % 16 == 0);

	HConstantBuffer hConstantBuffer;

	// Buffer Description
	D3D11_BUFFER_DESC BufferDescription;

	BufferDescription.Usage				= D3D11_USAGE_DEFAULT;
	BufferDescription.ByteWidth			= _sizeOf_a16;
	BufferDescription.BindFlags			= D3D11_BIND_CONSTANT_BUFFER;
	BufferDescription.CPUAccessFlags	= NULL;
	BufferDescription.MiscFlags			= NULL;

	// Subresource Data
	D3D11_SUBRESOURCE_DATA SubresourceData;

	SubresourceData.pSysMem				= _pData;
	SubresourceData.SysMemPitch			= NULL;
	SubresourceData.SysMemSlicePitch	= NULL; 

	// Create Buffer
	ID3D11Buffer* pConstantBuffer = nullptr;
	m_pDevice->CreateBuffer(&BufferDescription, &SubresourceData, &pConstantBuffer);

	hConstantBuffer = m_HandleManager.CreateHandle((ConstantBuffer*)new ConstantBuffer_DX11_0(pConstantBuffer, _eShaderType));
	m_hConstantBuffers.push_back(hConstantBuffer);
	return hConstantBuffer;
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetVertexFormatActive(VertexFormat_DX11_0* _pVertexFormat)
{
	m_pActiveVertexFormat	= _pVertexFormat;
	m_pActiveInputLayout	= nullptr;
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetVertexBufferActive(VertexBuffer_DX11_0* _pVertexBuffer, uint32 _nStartSlot, uint32 _nBuffers)
{
	m_pActiveVertexBuffer = _pVertexBuffer;

	UINT nStride			= _pVertexBuffer->GetVertexFormat()->GetVertexSize();
	UINT nOffset			= 0;
	ID3D11Buffer* pBuffer	= m_pActiveVertexBuffer->GetBuffer();

	m_pDeviceContext->IASetVertexBuffers(_nStartSlot, _nBuffers, &pBuffer, &nStride, &nOffset);

	SetVertexFormatActive(_pVertexBuffer->GetVertexFormat());
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetIndexBufferActive(IndexBuffer_DX11_0* _pIndexBuffer)
{
	m_pDeviceContext->IASetIndexBuffer(_pIndexBuffer->GetBuffer(), DXGI_FORMAT_R32_UINT, NULL);
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetConstantBufferActive(ConstantBuffer_DX11_0* _pConstantBuffer)
{
	// TODO:: Handle Multiable Buffers
	// Note: Group based on update frequency 

	ID3D11Buffer* pBuffer = _pConstantBuffer->GetBuffer();

	switch(_pConstantBuffer->GetShaderType())
	{
	case Shader::eSHADER_TYPE_VERTEX:
		{
			m_pDeviceContext->VSSetConstantBuffers(0, 1, &pBuffer);
		} break;
	case Shader::eSHADER_TYPE_PIXEL:
		{
			m_pDeviceContext->PSSetConstantBuffers(0, 1, &pBuffer);
		} break;
	case Shader::eSHADER_TYPE_COMPUTE:
	case Shader::eSHADER_TYPE_DOMAIN:
	case Shader::eSHADER_TYPE_GEOMETRY:
	case Shader::eSHADER_TYPE_HULL:
	default:
		{
		// TODO:: Throw Error
		} break;
	}
}

//---------------------------------------------------------------
void Renderer_DX11_0::UpdateBuffer(BaseBuffer_DX11_0* _pBuffer, void* _pData)
{
	m_pDeviceContext->UpdateSubresource(_pBuffer->GetBuffer(), NULL, NULL, _pData, NULL, NULL);
}

//---------------------------------------------------------------
// View Management
//---------------------------------------------------------------
void Renderer_DX11_0::SetFullscreen(bool _bFullscreen)
{
	m_pSwapChain->SetFullscreenState(m_bIsFullscreen = _bFullscreen, NULL);
}

//---------------------------------------------------------------
// DLL Interfacing
//---------------------------------------------------------------
extern "C"
{
	void DLLEXPORT CreateRenderer(HINSTANCE _hDLL, IRenderer** _pInterface)
	{
		if(!(*_pInterface))
		{
			(*_pInterface) = new Renderer_DX11_0();
		}
	}

	//---------------------------------------------------------------
	void DLLEXPORT ReleaseRenderer(IRenderer** _pInterface)
	{
		if((*_pInterface))
		{
			delete (*_pInterface);
			(*_pInterface) = nullptr;
		}
	}
}