//===============================================================
// File:	Renderer.cpp
// Purpose: Act as the direct Rendering Interface
//===============================================================
#include "Renderer.h"
using namespace Graphics;

//---------------------------------------------------------------
// Class Construction
//---------------------------------------------------------------
Renderer_DX11_0::Renderer_DX11_0()
{
	m_pDevice			= nullptr;
	m_pDeviceContext	= nullptr;
	m_pSwapChain		= nullptr;

	m_pBackBuffer		= nullptr;

	m_bIsFullscreen		= false;
}

//---------------------------------------------------------------
Renderer_DX11_0::~Renderer_DX11_0()
{
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
// Rendering Settings
//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetWidth()
{
	return m_StarupSettings.nWidth;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetHeight()
{
	return m_StarupSettings.nHeight;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetRefreshRate()
{
	return m_StarupSettings.nRefreshRate;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetMSAASamples()
{
	return m_StarupSettings.nMSAASamples;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetSampleQuality()
{
	return m_StarupSettings.nSampleQuality;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetBuffersCount()
{
	return m_StarupSettings.nBufferCount;
}

//---------------------------------------------------------------
Renderer_DX11_0::eDriverMode Renderer_DX11_0::GetDriverMode()
{
	return m_StarupSettings.eDriverMode;
}

//---------------------------------------------------------------
bool Renderer_DX11_0::GetDebugMode()
{
	return m_StarupSettings.bDebugMode;
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
Shader* Renderer_DX11_0::CompileFromFile(utf16* _szFile, utf8* _szFunction, Shader::eSHADER_TYPES _eShaderType)
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
			return new ComputeShader((ID3D11ComputeShader*)pShader);
		} break;
	case Shader::eSHADER_TYPE_DOMAIN:
		{
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "ds_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateDomainShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11DomainShader**) &pShader);
			return new DomainShader((ID3D11DomainShader*)pShader);
		} break;
	case Shader::eSHADER_TYPE_GEOMETRY:
		{ 
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "gs_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateGeometryShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11GeometryShader**) &pShader);
			return new GeometryShader((ID3D11GeometryShader*)pShader);
		} break;
	case Shader::eSHADER_TYPE_HULL:
		{ 		
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "hs_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateHullShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11HullShader**) &pShader);
			return new HullShader((ID3D11HullShader*)pShader);
		} break;
	case Shader::eSHADER_TYPE_PIXEL:
		{
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "ps_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreatePixelShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11PixelShader**) &pShader);
			return new PixelShader((ID3D11PixelShader*)pShader);
		} break;
	case Shader::eSHADER_TYPE_VERTEX:
		{ 
			D3DCompileFromFile(_szFile, NULL, NULL, _szFunction, "vs_5_0", NULL, NULL, &pCompiledCode, &pErrorMessage);
			m_pDevice->CreateVertexShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, (ID3D11VertexShader**)&pShader);
			return new VertexShader((ID3D11VertexShader*)pShader);
		} break;
	}

	return nullptr;
}

//---------------------------------------------------------------
// View Management
//---------------------------------------------------------------
bool Renderer_DX11_0::IsFullscreen()
{
	return m_bIsFullscreen;
}

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