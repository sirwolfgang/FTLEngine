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

}

//---------------------------------------------------------------
Renderer_DX11_0::~Renderer_DX11_0()
{

}

//---------------------------------------------------------------
// Rendering System Managment
//---------------------------------------------------------------
void Renderer_DX11_0::Initialize(Settings _tSettings)
{

}

//---------------------------------------------------------------
void Renderer_DX11_0::Startup()
{

}

//---------------------------------------------------------------
void Renderer_DX11_0::Shutdown()
{

}

//---------------------------------------------------------------
void Renderer_DX11_0::Restart()
{

}

//---------------------------------------------------------------
// Rendering Settings
//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetWidth()
{
	return NULL;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetHeight()
{
	return NULL;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetRefreshRate()
{
	return NULL;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetMSAASamples()
{
	return NULL;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetSampleQuality()
{
	return NULL;
}

//---------------------------------------------------------------
uint32 Renderer_DX11_0::GetBuffersCount()
{
	return NULL;
}

//---------------------------------------------------------------
Renderer_DX11_0::eDriverMode Renderer_DX11_0::GetDriverMode()
{
	return eDriverMode_Unspecified;
}

//---------------------------------------------------------------
bool Renderer_DX11_0::GetDebugMode()
{
	return false;
}

//---------------------------------------------------------------
// Draw Management
//---------------------------------------------------------------
void Renderer_DX11_0::ClearBuffer(float _fARGB[4])
{

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

}

//---------------------------------------------------------------
// View Management
//---------------------------------------------------------------
bool Renderer_DX11_0::IsFullscreen()
{
	return false;
}

//---------------------------------------------------------------
void Renderer_DX11_0::SetFullscreen(bool _bFullscreen)
{

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