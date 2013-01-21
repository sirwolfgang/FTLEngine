//===============================================================
// File:	Main.cpp
// Purpose: Entry Point for Graphics Test
//===============================================================
#include <FTLPlatform.h>
#include <FTLGraphics.h>
using Platform::Window;
using Graphics::Renderer;
using Graphics::RendererDLL;

int CALLBACK WinMain(HINSTANCE _hInstance, 
					 HINSTANCE _hPrevInstance, 
					 LPSTR _lpCmdLine, 
					 int _nCmdShow)
{
	Window window(_hInstance, _nCmdShow);
	window.Create(Platform::Window::eWindow_Mode_Normal, L"FTL Engine", 0, 0, 1024, 768);

	RendererDLL		rendererDLL;
	Renderer*		pRenderer;

	rendererDLL.Create(&pRenderer);
	rendererDLL.Release();

	while(window.Update());

	return NULL;
}