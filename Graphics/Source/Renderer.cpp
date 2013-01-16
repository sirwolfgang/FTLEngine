//===============================================================
// File:	Renderer.cpp
// Purpose: Act as the direct Rendering Interface
//===============================================================
#include "Renderer.h"
using namespace Graphics;

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
	m_pDevice			= nullptr;
	m_pDeviceContext	= nullptr;
	m_pSwapChain		= nullptr;
}

//---------------------------------------------------------------
Renderer::Renderer(Settings& _Settings)
{
	m_pDevice			= nullptr;
	m_pDeviceContext	= nullptr;
	m_pSwapChain		= nullptr;

	//------------------------------
	DXGI_SWAP_CHAIN_DESC SwapChainDesc;
	ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	SwapChainDesc.BufferDesc.Width						= _Settings.Width;					//* Resolution Width
	SwapChainDesc.BufferDesc.Height						= _Settings.Height;					//* Resolution Height
	SwapChainDesc.BufferDesc.RefreshRate.Numerator		= _Settings.RefreshRate;			//* RefeshRate
	SwapChainDesc.BufferDesc.RefreshRate.Denominator	= 1000;								//* RefeshRate
	SwapChainDesc.BufferDesc.Format						= DXGI_FORMAT_R8G8B8A8_UNORM;		//  Format
	//SwapChainDesc.BufferDesc.ScanlineOrdering			= ;									//  Scan Line Ordering
	//SwapChainDesc.BufferDesc.Scaling					= ;									//  Scaling Mode
	//SwapChainDesc.SampleDesc.Count					= ;									//* Multisamples Per Pixel
	//SwapChainDesc.SampleDesc.Quality					= ;									//* Quality Level
	SwapChainDesc.BufferUsage							= DXGI_USAGE_RENDER_TARGET_OUTPUT;	//  Buffer Usage
	SwapChainDesc.BufferCount							= 1;								//* Buffer Count
	SwapChainDesc.OutputWindow							= _Settings.hOutput;				//+ Handle To Output Window
	SwapChainDesc.Windowed								= true;								//* Windowed Mode
	//SwapChainDesc.SwapEffect							= ;									//  Swap Mode

	// create a device, device context and swap chain using the information in the scd struct
	D3D11CreateDeviceAndSwapChain(NULL,	//* Video Adapter
		D3D_DRIVER_TYPE_HARDWARE,		//* Driver Mode
		NULL,							//  DLL handle, software rasterizer
		NULL,							//+ Flags[Debuggable]
		NULL,
		NULL,
		D3D11_SDK_VERSION,				//  SDK Version
		&SwapChainDesc,
		&m_pSwapChain,
		&m_pDevice,
		NULL,
		&m_pDeviceContext);
}

//---------------------------------------------------------------
Renderer::~Renderer()
{
	if(m_pSwapChain)
	{
		m_pSwapChain->Release();
		m_pSwapChain = nullptr;
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
}