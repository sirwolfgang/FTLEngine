//===============================================================
// File:	ModuleManager.h
// Purpose: To Handle the base module managment interface
//===============================================================
#pragma once
#include <FTLPlatform.h>

namespace Core
{
	class ModuleManager
	{

	public:
		ModuleManager();
		~ModuleManager();

		virtual void Initialize();
		virtual void Startup();
		virtual void Shutdown();
		virtual void Update(float32 _fTime);
	};
}
