//===============================================================
// File:	WindowModule.h
// Purpose: To Handle the Platform Layer Window Rendering
//===============================================================
#pragma once
#include "../IModule.h"

namespace Core
{
	class WindowModule : public IModule
	{
	public:
		struct InitializationData
		{
			HINSTANCE	hInstance;
			int32		nCmdShow;
		};

	protected:
		Platform::Window m_Window;

	public:
		WindowModule();
		virtual ~WindowModule();

		virtual void Initialize(InitializationData& _InitializationData);
		virtual void Startup();
		virtual void Shutdown();
		virtual void Update(float32 _fTime);

		HWND GetHandle();
	};
}

#include "WindowModule.inl"