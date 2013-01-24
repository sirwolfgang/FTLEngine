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
	Window Window(_hInstance, _nCmdShow);
	Window.Create(Platform::Window::eWindow_Mode_Normal, L"FTL Engine", 0, 0, 1024, 768);

	RendererDLL		rendererDLL;
	Renderer*		pRenderer;

	rendererDLL.Create(&pRenderer);
	{
		Graphics::Renderer::Settings Settings;

		Settings.nWidth			= 1024;
		Settings.nHeight		= 768;
		Settings.nRefreshRate	= 0;
		Settings.nMSAASamples	= 1;
		Settings.nSampleQuality = 0;
		Settings.nBufferCount	= 1;
		Settings.eDriverMode	= Graphics::Renderer::eDriverMode_Hardware;
		Settings.hOutput		= Window.GetHandle();
		Settings.bDebugMode		= true;

		pRenderer->Initialize(Settings);
		pRenderer->Startup();
		{
			float Color[4] = {0.33f, 0.33f, 0.33f, 1.00f};
			pRenderer->ClearBackBuffer(Color);

			Graphics::Shader* VertexShader	= pRenderer->CompileFromFile(L"Source/Shader.hlsl", "VShader", Graphics::Shader::eSHADER_TYPE_VERTEX);
			Graphics::Shader* PixelShader	= pRenderer->CompileFromFile(L"Source/Shader.hlsl", "PShader", Graphics::Shader::eSHADER_TYPE_PIXEL);

			VertexShader->SetShaderActive();
			PixelShader->SetShaderActive();

			pRenderer->Present();

			while(Window.Update());

		}
		pRenderer->Shutdown();
	}
	rendererDLL.Release();

	return NULL;
}