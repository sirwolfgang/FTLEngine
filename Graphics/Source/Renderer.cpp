//===============================================================
// File:	Renderer.cpp
// Purpose: Act as the direct Rendering Interface
//===============================================================
#include "Renderer.h"
using namespace Graphics;

Renderer* Renderer::sm_pInstance = nullptr;

//---------------------------------------------------------------
Renderer::Settings::Settings()
{
	hOutput		= NULL;
	Width		= 1024;
	Height		= 768;
	RefreshRate = NULL;
}

//---------------------------------------------------------------
Renderer::Renderer()
{
	sm_pInstance		= this;

	m_pDevice			= nullptr;
	m_pDeviceContext	= nullptr;
	m_pSwapChain		= nullptr;
}

//---------------------------------------------------------------
Renderer::Renderer(Settings& _Settings)
{
	sm_pInstance		= this;

	m_pDevice			= nullptr;
	m_pDeviceContext	= nullptr;
	m_pSwapChain		= nullptr;

	//------------------------------
	DXGI_SWAP_CHAIN_DESC SwapChainDesc;
	ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	SwapChainDesc.BufferDesc.Width						= _Settings.Width;							//* Resolution Width
	SwapChainDesc.BufferDesc.Height						= _Settings.Height;							//* Resolution Height
	SwapChainDesc.BufferDesc.RefreshRate.Numerator		= _Settings.RefreshRate;					//* RefeshRate
	SwapChainDesc.BufferDesc.RefreshRate.Denominator	= 1000;										//* RefeshRate
	SwapChainDesc.BufferDesc.Format						= DXGI_FORMAT_R8G8B8A8_UNORM;				//  Format
	SwapChainDesc.BufferDesc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;		//  Scan Line Ordering
	SwapChainDesc.BufferDesc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;			//  Scaling Mode
	SwapChainDesc.SampleDesc.Count						= 1;										//* Multisamples Per Pixel
	SwapChainDesc.SampleDesc.Quality					= 0;										//* Quality Level
	SwapChainDesc.BufferUsage							= DXGI_USAGE_RENDER_TARGET_OUTPUT;			//  Buffer Usage
	SwapChainDesc.BufferCount							= 1;										//* Buffer Count
	SwapChainDesc.OutputWindow							= _Settings.hOutput;						//+ Handle To Output Window
	SwapChainDesc.Windowed								= true;										//* Windowed Mode
	SwapChainDesc.SwapEffect							= DXGI_SWAP_EFFECT_DISCARD;					//  Swap Mode
	SwapChainDesc.Flags									= DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;	// Flags

	// create a device, device context and swap chain using the information in the scd struct
	HRESULT hResult = D3D11CreateDeviceAndSwapChain(NULL,	//* Video Adapter
		D3D_DRIVER_TYPE_HARDWARE,		//* Driver Mode
		NULL,							//  DLL handle, software rasterizer
		NULL,							//+ Flags[Debuggable]
		NULL,
		NULL,
		D3D11_SDK_VERSION,				//  SDK Version
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
	Viewport.Width		= (float)_Settings.Width;
	Viewport.Height		= (float)_Settings.Height;

	m_pDeviceContext->RSSetViewports(1, &Viewport);
}

//---------------------------------------------------------------
Renderer::~Renderer()
{
	if(m_pSwapChain)
	{
		m_pSwapChain->SetFullscreenState(false, NULL);
		m_pSwapChain->Release();
		m_pSwapChain = nullptr;
	}

	if(m_pBackBuffer)
	{
		m_pBackBuffer->Release();
		m_pBackBuffer = nullptr;
	}

	if(m_pDevice)
	{
		m_pDevice->Release();
		m_pDevice = nullptr;
	}

	if(m_pDeviceContext)
	{
		m_pDeviceContext->Release();
		m_pDeviceContext = nullptr;
	}

	if(sm_pInstance)
	{
		sm_pInstance = nullptr;
	}
}

//---------------------------------------------------------------
void Renderer::RenderFrame()
{
	// Clear Buffer
	float ClearColor[4] = {0.33f, 0.33f, 0.33f, 1.0f};
	m_pDeviceContext->ClearRenderTargetView(m_pBackBuffer, ClearColor);

	// Present
	m_pSwapChain->Present(0, 0);
}

//---------------------------------------------------------------
Shader* Renderer::CompileShaderFromFile(utf16* _szFilename, eShaderType _eShaderType)
{
	Shader*		pShader			= nullptr;
	ID3DBlob*	pCompiledCode	= nullptr;
	ID3DBlob*	pError			= nullptr;

	// TODO:: Error Handling

	switch(_eShaderType)
	{
	case eShaderType_Compute:
		{
			pShader = new ComputeShader();
			D3DCompileFromFile(_szFilename, NULL, NULL, NULL, "cs_5_0", NULL, NULL, &pCompiledCode, &pError);
			m_pDevice->CreateComputeShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, &((ComputeShader*)pShader)->m_pShader);
		} break;
	case eShaderType_Domain:
		{
			pShader = new DomainShader();
			D3DCompileFromFile(_szFilename, NULL, NULL, NULL, "ds_5_0", NULL, NULL, &pCompiledCode, &pError);
			m_pDevice->CreateDomainShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, &((DomainShader*)pShader)->m_pShader);
		} break;
	case eShaderType_Geometry:
		{
			pShader = new GeometryShader();
			D3DCompileFromFile(_szFilename, NULL, NULL, NULL, "gs_5_0", NULL, NULL, &pCompiledCode, &pError);
			m_pDevice->CreateGeometryShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, &((GeometryShader*)pShader)->m_pShader);
		} break;
	case eShaderType_Hull:
		{
			pShader = new HullShader();
			D3DCompileFromFile(_szFilename, NULL, NULL, NULL, "hs_5_0", NULL, NULL, &pCompiledCode, &pError);
			m_pDevice->CreateHullShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, &((HullShader*)pShader)->m_pShader);
		} break;
	case eShaderType_Pixel:
		{
			pShader = new PixelShader();
			D3DCompileFromFile(_szFilename, NULL, NULL, NULL, "ps_5_0", NULL, NULL, &pCompiledCode, &pError);
			m_pDevice->CreatePixelShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, &((PixelShader*)pShader)->m_pShader);
		} break;
	case eShaderType_Vertex:
		{
			pShader = new VertexShader();
			D3DCompileFromFile(_szFilename, NULL, NULL, NULL, "vs_5_0", NULL, NULL, &pCompiledCode, &pError);
			m_pDevice->CreateVertexShader(pCompiledCode->GetBufferPointer(), pCompiledCode->GetBufferSize(), NULL, &((VertexShader*)pShader)->m_pShader);
		} break;
	case eShaderType_Unspecified:
	default:
		{
			// TODO:: Handle Error
		} break;
	}

	return pShader;
}