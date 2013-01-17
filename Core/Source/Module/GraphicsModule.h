//===============================================================
// File:	GraphicsModule.h
// Purpose: To Handle Startup and Shutdown, and common interface
//			for graphics engine
//===============================================================
#pragma once
#include "../DLL.h"
#include <FTLGraphics.h>

namespace Core
{
	class CORE_API GraphicsModule : public Platform::IModule
	{
		Graphics::Renderer* m_pRenderer;

	public:
		GraphicsModule();
		~GraphicsModule();

		virtual void Startup();
		virtual void Shutdown();
	};
}