//===============================================================
// File:	Adapters.h
// Purpose: To handle enumeration of adapters
//===============================================================
#pragma once
#include "DLL.h"
#include "DirectX.h"
#include <FTLPlatform.h>

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
	struct GRAPHICS_API Monitor
	{
		utf16			Name[32];
		RECT			Coordinates;
		uint32			NumberOfDisplayModes;
		DisplayMode*	DisplayModes;

		Monitor();
		~Monitor();
	};

	//---------------------------------------------------------------
	struct GRAPHICS_API Adapter
	{
		utf16		Name[128];
		memsize		DedicatedVideoMemory;
		memsize		DedicatedSystemMemory;
		memsize		SharedSystemMemory;
		uint32		NumberOfMonitors;
		Monitor*	Monitors;

		Adapter();
		~Adapter();
	};

	//---------------------------------------------------------------
	GRAPHICS_API void EnumerateAdapters(uint32* _NumOfAdapters, Adapter** _Adapters);
}