//===============================================================
// File:	Adapters.h
// Purpose: To handle enumeration of adapters
//===============================================================
#pragma once
#include <FTLCore.h>
#include "DLL.h"

namespace Graphics
{
	//---------------------------------------------------------------
	struct GRAPHICS_API DisplayMode
	{
		uint32	Width;
		uint32	Height;
		uint32	RefreshRate; // RefreshRate (hz) = RefreshRate / 1000

		DisplayMode();
		~DisplayMode();
	};

	//---------------------------------------------------------------
	struct GRAPHICS_API Adapter
	{
		utf16			Name[128];
		memsize			DedicatedVideoMemory;
		memsize			DedicatedSystemMemory;
		memsize			SharedSystemMemory;
		uint32			NumberOfDisplayModes;
		DisplayMode*	DisplayModes;

		Adapter();
		~Adapter();
	};

	//---------------------------------------------------------------
	GRAPHICS_API void EnumerateAdapters(uint32* _NumOfAdapters, Adapter** _Adapters);
}