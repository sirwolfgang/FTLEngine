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
Graphics::Adapter::Adapter() : DedicatedVideoMemory(NULL), DedicatedSystemMemory(NULL), SharedSystemMemory(NULL), NumberOfDisplayModes(NULL), DisplayModes(nullptr)
{
	memset(Name, NULL, sizeof(utf16) * 128);
}

//---------------------------------------------------------------
Graphics::Adapter::~Adapter()
{
	if(DisplayModes)
	{
		delete[] DisplayModes;
		DisplayModes = nullptr;
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
	UINT				numDisplayModes = NULL;
	HREFTYPE			hResult			= NULL;

	// TODO:: Add Error Checking/Handling
	hResult = CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)&pFactory);
	if(FAILED(hResult))
			return;

	// Find Number of Adapters
	for((*_NumOfAdapters) = 0; pFactory->EnumAdapters1((*_NumOfAdapters), &pAdapter) != DXGI_ERROR_NOT_FOUND; ++(*_NumOfAdapters));
	(*_Adapters) = new Adapter[(*_NumOfAdapters)];

	for(uint32 i = 0; pFactory->EnumAdapters1(i, &pAdapter) != DXGI_ERROR_NOT_FOUND; ++i) 
	{
		hResult = pAdapter->GetDesc1(&AdapterDesc);
		if(FAILED(hResult))
			continue;

		memcpy_s((*_Adapters)[i].Name, 128, AdapterDesc.Description, 128);
		(*_Adapters)[i].DedicatedVideoMemory	= AdapterDesc.DedicatedVideoMemory;
		(*_Adapters)[i].DedicatedSystemMemory	= AdapterDesc.DedicatedSystemMemory;
		(*_Adapters)[i].SharedSystemMemory		= AdapterDesc.SharedSystemMemory;

		hResult = pAdapter->EnumOutputs(0, &pOutput);
		if(FAILED(hResult))
			continue;

		hResult = pOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, NULL, &numDisplayModes, nullptr);
		if(FAILED(hResult))
			continue;

		(*_Adapters)[i].NumberOfDisplayModes = numDisplayModes;

		DisplayModeList					= new DXGI_MODE_DESC[numDisplayModes];
		(*_Adapters)[i].DisplayModes	= new DisplayMode[numDisplayModes];

		hResult = pOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, NULL, &numDisplayModes, DisplayModeList);
		if(FAILED(hResult))
			continue;

		for(uint32 j = 0; j < numDisplayModes; ++j)
		{
			(*_Adapters)[i].DisplayModes->Width			= DisplayModeList->Width;
			(*_Adapters)[i].DisplayModes->Height		= DisplayModeList->Height;
			(*_Adapters)[i].DisplayModes->RefreshRate	= (float32)DisplayModeList->RefreshRate.Numerator / (float32)DisplayModeList->RefreshRate.Denominator;
		}

		delete[] DisplayModeList;
	}

}
