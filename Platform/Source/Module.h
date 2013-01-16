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
		virtual void Startup()	= 0;
		virtual void Shutdown() = 0;
	};
}