//===============================================================
// File:	ModuleManager.h
// Purpose: To Handle the base module managment interface
//===============================================================
#pragma once
#include "../DLL.h"
#include <FTLPlatform.h>

namespace Core
{
	class CORE_API ModuleManager : public Platform::IModule
	{
	public:
		ModuleManager();
		~ModuleManager();

		virtual void Startup();
		virtual void Shutdown();
	};
}
