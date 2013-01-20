//===============================================================
// File:	ModuleManager.h
// Purpose: To Handle the base module managment interface
//===============================================================
#pragma once
#include "GraphicsModule.h"

namespace Core
{
	class CORE_API ModuleManager //: public Platform::IModule
	{
		GraphicsModule	m_GraphicsModule;

	public:
		ModuleManager();
		~ModuleManager();

		virtual void Startup();
		virtual void Shutdown();
		virtual void Update(float32 _fTime);
	};
}
