//===============================================================
// File:	GraphicsModule.h
// Purpose: To Handle Startup and Shutdown, and common interface
//			for graphics engine
//===============================================================
#pragma once
#include "../DLL.h"
#include <FTLGraphics.h>
#include "WindowModule.h"

namespace Core
{
	class CORE_API GraphicsModule : public Platform::IModule
	{
		WindowModule		m_WindowModule;
		Graphics::Renderer* m_pRenderer;

	public:
		GraphicsModule();
		~GraphicsModule();

		virtual void Startup();
		virtual void Shutdown();
		virtual void Update(float32 _fTime);
	};
}