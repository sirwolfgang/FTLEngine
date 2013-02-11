//===============================================================
// File:	Main.cpp
// Purpose: Entry Point for Graphics Test
//===============================================================
#include <FTLPlatform.h>
#include <FTLGraphics.h>
using Platform::Window;
using Graphics::Renderer;
using Graphics::RendererDLL;

struct Vertex
{
	float Position[3];
	float Color[4];
};

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

			// Shaders
			Graphics::HShader VertexShader	= pRenderer->CompileFromFile(L"Source/Shader.hlsl", "VShader", Graphics::Shader::eSHADER_TYPE_VERTEX);
			Graphics::HShader PixelShader	= pRenderer->CompileFromFile(L"Source/Shader.hlsl", "PShader", Graphics::Shader::eSHADER_TYPE_PIXEL);

			// Vertex Format
			Graphics::VertexFormat::VertDataPair VertFormat[2] = 
			{
				{ Graphics::VertexFormat::eSEMANTICS_POSITION,	Graphics::VertexFormat::eDATASIZES_FLOAT3},
				{ Graphics::VertexFormat::eSEMANTICS_COLOR,		Graphics::VertexFormat::eDATASIZES_FLOAT4},
			};
			
			Graphics::HVertexFormat hVertexFormat = pRenderer->CreateVertexFormat(VertFormat, 2);

			// Vertex Buffer
			Vertex VertexBuffer[] =
			{
				{ 0.00f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f},
				{ 0.45f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
				{-0.45f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f},
			};

			Graphics::HVertexBuffer hVertexBuffer = pRenderer->CreateVertexBuffer(3, &VertexBuffer, hVertexFormat);

			// Activate Settings
			VertexShader->SetShaderActive();
			PixelShader->SetShaderActive();

			hVertexBuffer->SetBufferActive();
			pRenderer->SetPrimitiveTopology(Graphics::Primitive::eTOPOLOGY_TRIANGLELIST);

			pRenderer->Draw(3, 0);

			pRenderer->Present();

			while(Window.Update());

		}
		pRenderer->Shutdown();
	}
	rendererDLL.Release();

	return NULL;
}