//===============================================================
// File:	IModule.h
// Purpose: Module Common Interface
//===============================================================
#pragma once
#include <FTLPlatform.h>

namespace Core
{
	class IModule
	{
	public:
		virtual ~IModule(){}

		virtual void Startup()				= 0;
		virtual void Shutdown()				= 0;
		virtual void Update(float32 _fTime)	= 0;
	};
}