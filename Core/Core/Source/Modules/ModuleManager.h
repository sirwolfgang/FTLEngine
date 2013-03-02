//===============================================================
// File:	ModuleManager.h
// Purpose: To Handle the base module managment interface
//===============================================================
#pragma once
#include "IModule.h"

namespace Core
{
	class ModuleManager : public IModule
	{

	public:
		ModuleManager();
		virtual ~ModuleManager();

		virtual void Initialize();
		virtual void Startup();
		virtual void Shutdown();
		virtual void Update(float32 _fTime);
	};
}
