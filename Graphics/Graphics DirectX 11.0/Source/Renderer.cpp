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
// Class Construction
//---------------------------------------------------------------
Renderer_DX11_0::Renderer_DX11_0() 
	: m_pDevice(nullptr), 
	m_pDeviceContext(nullptr), 
	m_pSwapChain(nullptr), 
	m_pBackBuffer(nullptr), 
	m_bIsFullscreen(false), 
	m_pActiveComputeShader(nullptr), 
	m_pActiveDomainShader(nullptr), 
	m_pActiveGeometryShader(nullptr), 
	m_pActiveHullShader(nullptr), 
	m_pActivePixelShader(nullptr), 
	m_pActiveVertexShader(nullptr)
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
	m_StarupSettings = _tSettings;
}

//---------------------------------------------------------------
void Renderer_DX11_0::Startup()
{
	DXGI_SWAP_CHAIN_DESC SwapChainDesc;
	ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	SwapChainDesc.BufferDesc.Width						= m_StarupSettings.nWidth;					//* Resolution Width
	SwapChainDesc.BufferDesc.Height						= m_StarupSettings.nHeight;					//* Resolution Height
	SwapChainDesc.BufferDesc.RefreshRate.Numerator		= m_StarupSettings.nRefreshRate;			//* RefeshRate
	SwapChainDesc.BufferDesc.RefreshRate.Denominator	= 1000;										//* RefeshRate
	SwapChainDesc.BufferDesc.Format						= DXGI_FORMAT_R8G8B8A8_UNORM;				//  Format
	SwapChainDesc.BufferDesc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;		//  Scan Line Ordering
	SwapChainDesc.BufferDesc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;			//  Scaling Mode
	SwapChainDesc.SampleDesc.Count						= m_StarupSettings.nMSAASamples;			//* Multisamples Per Pixel
	SwapChainDesc.SampleDesc.Quality					= m_StarupSettings.nSampleQuality;			//* Quality Level
	SwapChainDesc.BufferUsage							= DXGI_USAGE_RENDER_TARGET_OUTPUT;			//  Buffer Usage
	SwapChainDesc.BufferCount							= m_StarupSettings.nBufferCount;			//* Buffer Count
	SwapChainDesc.OutputWindow							= m_StarupSettings.hOutput;					//+ Handle To Output Window
	SwapChainDesc.Windowed								= true;										//* Windowed Mode
	SwapChainDesc.SwapEffect							= DXGI_SWAP_EFFECT_DISCARD;					//  Swap Mode
	SwapChainDesc.Flags									= NULL;										// Flags

	m_bIsFullscreen		= false;

	//------------------------------
	D3D_DRIVER_TYPE DriverType;

	switch (m_StarupSettings.eDriverMode)
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
		(m_StarupSettings.eDriverMode) ? D3D11_CREATE_DEVICE_DEBUG : NULL,
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
	Viewport.Width		= (float)m_StarupSettings.nWidth;
	Viewport.Height		= (float)m_StarupSettings.nHeight;

	m_pDeviceContext->RSSetViewports(1, &Viewport);
}

//---------------------------------------------------------------
void Renderer_DX11_0::Shutdown()
{
	// TODO:: Clean up Memory, Handles
	// m_HandleManager

	RELEASE_COM(m_pBackBuffer);

	if(m_pSwapChain)
		m_pSwapChain->SetFullscreenState(false, NULL);

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
void Renderer_DX11_0::PreDraw()
{

}

//---------------------------------------------------------------
void Renderer_DX11_0::PostDraw()
{

}

//---------------------------------------------------------------
void Renderer_DX11_0::Present()
{
	m_pSwapChain->Present(0, 0);
}

//---------------------------------------------------------------
// Shader Management
//---------------------------------------------------------------
Handle<Shader> Renderer_DX11_0::CompileFromFile(utf16* _szFile, utf8* _szFunction, Shader::eSHADER_TYPES _eShaderType)
{
	ID3DBlob*	pCompiledCode	= nullptr;
	ID3DBlob*	pErrorMessage	= nullptr;
	void*		pShader			= nullptr;

	switch (_eShaderType)
	{
	case Shader::eSHADER_TYPE_COMPUTE:
		{
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "cs_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateComputeShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11ComputeShader**) &pShader);
			return m_HandleManager.CreateHandle((Shader*) new ComputeShader_DX11_0((ID3D11ComputeShader*)pShader));
		} break;
	case Shader::eSHADER_TYPE_DOMAIN:
		{
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "ds_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateDomainShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11DomainShader**) &pShader);
			return m_HandleManager.CreateHandle((Shader*) new DomainShader_DX11_0((ID3D11DomainShader*)pShader));
		} break;
	case Shader::eSHADER_TYPE_GEOMETRY:
		{ 
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "gs_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateGeometryShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11GeometryShader**) &pShader);
			return m_HandleManager.CreateHandle((Shader*) new GeometryShader_DX11_0((ID3D11GeometryShader*)pShader));
		} break;
	case Shader::eSHADER_TYPE_HULL:
		{ 		
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "hs_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateHullShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11HullShader**) &pShader);
			return m_HandleManager.CreateHandle((Shader*) new HullShader_DX11_0((ID3D11HullShader*)pShader));
		} break;
	case Shader::eSHADER_TYPE_PIXEL:
		{
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "ps_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreatePixelShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11PixelShader**) &pShader);
			return m_HandleManager.CreateHandle((Shader*) new PixelShader_DX11_0((ID3D11PixelShader*)pShader));
		} break;
	case Shader::eSHADER_TYPE_VERTEX:
		{ 
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "vs_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateVertexShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11VertexShader**)&pShader);
			return m_HandleManager.CreateHandle((Shader*) new VertexShader_DX11_0((ID3D11VertexShader*)pShader));
		} break;
	}

	return Handle<Shader>();
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetShaderActive(HShader _hShader)
{
	SetShaderActive(_hShader.RetrieveEntry());
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetShaderActive(Shader* _pShader)
{
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
Handle<VertexFormat> Renderer_DX11_0::CreateVertexFormat(VertexFormat::VertDataPair _VertexFormatArray[], uint32 _nLength)
{
	return m_HandleManager.CreateHandle((VertexFormat*)new VertexFormat_DX11_0(_VertexFormatArray, _nLength));
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetVertexFormatActive(HVertexFormat _hVertexFormat)
{
	SetVertexFormatActive((VertexFormat_DX11_0*)_hVertexFormat.RetrieveEntry());
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetVertexFormatActive(VertexFormat_DX11_0* _pVertexFormat)
{
	m_pActiveVertexFormat = _pVertexFormat;

	//TODO:: Bind InputLayout_DX11_0, based on Actove VertexBuffer && Active Shader Pair 
	//Renderer_DX11_0::Instance()->DeviceContext()->IASetInputLayout_DX11_0(
}

//---------------------------------------------------------------
HVertexBuffer Renderer_DX11_0::CreateVertexBuffer(uint32 _nBufferSize, void* _pData)
{
	// Buffer Description
	D3D11_BUFFER_DESC BufferDescription;

	BufferDescription.Usage				= D3D11_USAGE_DEFAULT;
	BufferDescription.ByteWidth			= _nBufferSize;
	BufferDescription.BindFlags			= D3D11_BIND_VERTEX_BUFFER;
	BufferDescription.CPUAccessFlags	= NULL;
	BufferDescription.MiscFlags			= NULL;

	// Subresource Data
	D3D11_SUBRESOURCE_DATA SubresourceData;

	SubresourceData.pSysMem				= _pData;
	SubresourceData.SysMemPitch			= NULL;
	SubresourceData.SysMemSlicePitch	= NULL; 

	// Create Buffer
	ID3D11Buffer* pVertexBuffer = nullptr;
	m_pDevice->CreateBuffer(&BufferDescription, &SubresourceData, &pVertexBuffer);

	return HVertexBuffer();
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetVertexBufferActive(HVertexBuffer _hVertexBuffer)
{
	SetVertexBufferActive((VertexBuffer_DX11_0*)_hVertexBuffer.RetrieveEntry());
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetVertexBufferActive(VertexBuffer_DX11_0* _pVertexBuffer)
{
	m_pActiveVertexBuffer = _pVertexBuffer;
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
	void DLLEXPORT CreateRenderer(HINSTANCE _hDLL, Renderer** _pInterface)
	{
		if(!(*_pInterface))
		{
			(*_pInterface) = new Renderer_DX11_0();
		}
	}

	//---------------------------------------------------------------
	void DLLEXPORT ReleaseRenderer(Renderer** _pInterface)
	{
		if((*_pInterface))
		{
			delete (*_pInterface);
			(*_pInterface) = nullptr;
		}
	}
}