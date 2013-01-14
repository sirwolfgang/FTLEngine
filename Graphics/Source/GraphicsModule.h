//===============================================================
// File:	GraphicsModule.h
// Purpose: To Handle Startup and Shutdown, and common interface
//			for graphics engine
//===============================================================
#pragma once
#include "DLL.h"
#include <FTLCore.h>

namespace Graphics
{
	class GRAPHICS_API GraphicsModule : public Core::IModule
	{
	public:
		GraphicsModule();
		~GraphicsModule();

		virtual void Startup();
		virtual void Shutdown();
	};
}