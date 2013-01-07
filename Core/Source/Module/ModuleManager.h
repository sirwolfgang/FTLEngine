//===============================================================
// File:	ModuleManager.h
// Purpose: To Handle the base module managment interface
//===============================================================
#pragma once
#include "../DLL.h"

namespace Core
{
	class CORE_API ModuleManager
	{
	public:
		ModuleManager();
		~ModuleManager();

		void Startup();
		void Shutdown();
	};
}
