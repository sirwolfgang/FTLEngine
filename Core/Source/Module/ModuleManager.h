//===============================================================
// File:	ModuleManager.h
// Purpose: To Handle the base module managment interface
//===============================================================
#pragma once
#include "../DLL.h"
#include "Module.h"

namespace Core
{
	class CORE_API ModuleManager : public IModule
	{
	public:
		ModuleManager();
		~ModuleManager();

		virtual void Startup();
		virtual void Shutdown();
	};
}
