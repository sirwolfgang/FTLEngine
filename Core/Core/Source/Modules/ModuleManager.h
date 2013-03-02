//===============================================================
// File:	ModuleManager.h
// Purpose: To Handle the base module managment interface
//===============================================================
#pragma once
#include "IModule.h"

#include "Graphics\WindowModule.h"

namespace Core
{
	class ModuleManager : public IModule
	{
	public:
		struct InitializationData
		{
			HINSTANCE	hInstance;
			int32		nCmdShow;
		};

	protected:
		WindowModule m_windowModule;

	public:
		ModuleManager();
		virtual ~ModuleManager();

		virtual void Initialize(InitializationData& _InitializationData);
		virtual void Startup();
		virtual void Shutdown();
		virtual void Update(float32 _fTime);
	};
}
