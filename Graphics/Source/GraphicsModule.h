//===============================================================
// File:	GraphicsModule.h
// Purpose: To Handle Startup and Shutdown, and common interface
//			for graphics engine
//===============================================================
#pragma once
#include "DLL.h"
#include <FTLPlatform.h>

namespace Graphics
{
	class GRAPHICS_API Renderer;
	class GRAPHICS_API GraphicsModule : public Platform::IModule
	{
		Renderer* m_pRenderer;

	public:
		GraphicsModule();
		~GraphicsModule();

		virtual void Startup();
		virtual void Shutdown();
	};
}