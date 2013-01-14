//===============================================================
// File:	Adapters.cpp
// Purpose: To handle enumeration of adapters
//===============================================================
#include "Adapters.h"

//---------------------------------------------------------------
Graphics::DisplayMode::DisplayMode() : Width(NULL), Height(NULL), RefreshRate(NULL)
{

}

//---------------------------------------------------------------
Graphics::DisplayMode::~DisplayMode()
{

}

//---------------------------------------------------------------
Graphics::Monitor::Monitor() : NumberOfDisplayModes(NULL), DisplayModes(nullptr)
{
	memset(Name, NULL, sizeof(utf16) * 32);
	Coordinates.top = Coordinates.left = Coordinates.bottom = Coordinates.right = NULL;
}

//---------------------------------------------------------------
Graphics::Monitor::~Monitor()
{
	if(DisplayModes)
	{
		delete[] DisplayModes;
		DisplayModes = nullptr;
	}
}

//---------------------------------------------------------------
Graphics::Adapter::Adapter() : DedicatedVideoMemory(NULL), DedicatedSystemMemory(NULL), SharedSystemMemory(NULL), NumberOfMonitors(NULL), Monitors(nullptr)
{
	memset(Name, NULL, sizeof(utf16) * 128);
}

//---------------------------------------------------------------
Graphics::Adapter::~Adapter()
{
	if(Monitors)
	{
		delete[] Monitors;
		Monitors = nullptr;
	}
}

//---------------------------------------------------------------
GRAPHICS_API void Graphics::EnumerateAdapters(uint32* _NumOfAdapters, Adapter** _Adapters)
{
	(*_NumOfAdapters)	= NULL;
	(*_Adapters)		= nullptr;

	IDXGIFactory1*	pFactory		= nullptr;
	IDXGIAdapter1*	pAdapter		= nullptr;
	IDXGIOutput*	pOutput			= nullptr;
	DXGI_MODE_DESC* DisplayModeList = nullptr;

	DXGI_ADAPTER_DESC1	AdapterDesc;
	DXGI_OUTPUT_DESC	MonitorDesc;
	UINT				numDisplayModes = NULL;

	// Create the DXGI Interface
	if(FAILED(CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)&pFactory)))
		return;

	// Find Number of Adapters
	for((*_NumOfAdapters) = 0; !FAILED(pFactory->EnumAdapters1((*_NumOfAdapters), &pAdapter)); ++(*_NumOfAdapters));
	(*_Adapters) = new Adapter[(*_NumOfAdapters)];

	// Loop Through the Adapters
	for(uint32 i = 0; !FAILED(pFactory->EnumAdapters1(i, &pAdapter)); ++i) 
	{
		// Get Device Description
		if(FAILED(pAdapter->GetDesc1(&AdapterDesc)))
			continue;

		memcpy_s((*_Adapters)[i].Name, 128, AdapterDesc.Description, 128);
		(*_Adapters)[i].DedicatedVideoMemory	= AdapterDesc.DedicatedVideoMemory;
		(*_Adapters)[i].DedicatedSystemMemory	= AdapterDesc.DedicatedSystemMemory;
		(*_Adapters)[i].SharedSystemMemory		= AdapterDesc.SharedSystemMemory;

		// Get Number of Monitors
		for((*_Adapters)[i].NumberOfMonitors = 0; !FAILED(pAdapter->EnumOutputs((*_Adapters)[i].NumberOfMonitors, &pOutput)); ++(*_Adapters)[i].NumberOfMonitors);
		(*_Adapters)[i].Monitors = new Monitor[(*_Adapters)[i].NumberOfMonitors];

		// Get Adapter Output
		for(uint32 j = 0; !FAILED(pAdapter->EnumOutputs(j, &pOutput)); ++j)
		{
			// Get Monitor Information
			if(FAILED(pOutput->GetDesc(&MonitorDesc)))
				continue;

			memcpy_s((*_Adapters)[i].Monitors[j].Name, 32, MonitorDesc.DeviceName, 32);
			(*_Adapters)[i].Monitors[j].Coordinates = MonitorDesc.DesktopCoordinates;

			// Find DisplayMode List
			// Note: If you wish to support TVs, use flag DXGI_ENUM_MODES_INTERLACED
			if(FAILED(pOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, NULL, &numDisplayModes, nullptr)))
				continue;

			(*_Adapters)[i].Monitors[j].NumberOfDisplayModes	= numDisplayModes;
			(*_Adapters)[i].Monitors[j].DisplayModes			= new DisplayMode[numDisplayModes];
			DisplayModeList										= new DXGI_MODE_DESC[numDisplayModes];

			// Get DisplayMode List
			if(FAILED(pOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, NULL, &numDisplayModes, DisplayModeList)))
				continue;

			for(uint32 k = 0; k < numDisplayModes; ++k)
			{
				(*_Adapters)[i].Monitors[j].DisplayModes[k].Width		= DisplayModeList[k].Width;
				(*_Adapters)[i].Monitors[j].DisplayModes[k].Height		= DisplayModeList[k].Height;
				(*_Adapters)[i].Monitors[j].DisplayModes[k].RefreshRate	= DisplayModeList[k].RefreshRate.Numerator;
			}

			delete[] DisplayModeList;
		}
	}

}
