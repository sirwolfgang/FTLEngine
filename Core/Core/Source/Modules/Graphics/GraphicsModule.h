//===============================================================
// File:	GraphicsModule.h
// Purpose: To Handle the Game Graphics
//===============================================================
#pragma once
#include "../IModule.h"
#include "WindowModule.h"
#include <FTLGraphics.h>

namespace Core
{
	class GraphicsModule : public IModule
	{
	public:
		struct InitializationData
		{
			HINSTANCE	hInstance;
			int32		nCmdShow;
		};

	protected:
		WindowModule m_windowModule;

		Graphics::RendererDLL	m_RendererDLL;
		Graphics::Renderer*		m_pRenderer;

	public:
		GraphicsModule();
		virtual ~GraphicsModule();

		virtual void Initialize(InitializationData& _InitializationData);
		virtual void Startup();
		virtual void Shutdown();
		virtual void Update(float32 _fTime);
	};
}
