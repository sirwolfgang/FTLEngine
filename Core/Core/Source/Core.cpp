//===============================================================
// File:	Core.h
// Purpose: Act as the class and interface for the DLL
//===============================================================
#include "Core.h"
using namespace Engine;

//---------------------------------------------------------------
Core_Library::Core_Library()
{

}

//---------------------------------------------------------------
Core_Library::~Core_Library()
{

}

//===============================================================
// DLL Interfacing
//===============================================================
extern "C"
{
	void __declspec(dllexport) CreateCore(HINSTANCE _hDLL, Core** _pInterface)
	{
		if(!(*_pInterface))
		{
			(*_pInterface) = new Core_Library();
		}
	}

	//---------------------------------------------------------------
	void __declspec(dllexport) ReleaseCore(Core** _pInterface)
	{
		if((*_pInterface))
		{
			delete (*_pInterface);
			(*_pInterface) = nullptr;
		}
	}
}