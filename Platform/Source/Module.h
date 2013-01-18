//===============================================================
// File:	Module.h
// Purpose: Include point for Module Managment
//===============================================================
#pragma once
#include "DLL.h"

namespace Platform
{
	class PLATFORM_API IModule
	{
	public:
		virtual void Startup()				= NULL;
		virtual void Shutdown()				= NULL;
		virtual void Update(float32 _fTime) = NULL;
	};
}