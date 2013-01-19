//===============================================================
// File:	WindowModule.h
// Purpose: To Handle Startup and Shutdown, and common interface
//			for graphics engine
//===============================================================
#pragma once
#include "../DLL.h"
#include <FTLPlatform.h>

namespace Core
{
	class CORE_API WindowModule : public Platform::IModule
	{
		Platform::Window* m_pWindow;

	public:
		WindowModule();
		~WindowModule();

		virtual void Startup();
		virtual void Shutdown();
		virtual void Update(float32 _fTime);

		Platform::Window* Window();
	};
}

#include "WindowModule.inl"