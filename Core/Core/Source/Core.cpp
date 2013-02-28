//===============================================================
// File:	Core.h
// Purpose: Act as the class and interface for the DLL
//===============================================================
#include "Core.h"
using namespace Core;

//---------------------------------------------------------------
CoreInterface_DLL::CoreInterface_DLL()
{

}

//---------------------------------------------------------------
CoreInterface_DLL::~CoreInterface_DLL()
{

}

//---------------------------------------------------------------
Engine* CoreInterface_DLL::InitializeEngine(Engine::InitializationData& _InitializationData)
{
	return nullptr;
}

//===============================================================
// DLL Interfacing
//===============================================================
extern "C"
{
	void __declspec(dllexport) CreateCoreInterface(HINSTANCE _hDLL, CoreInterface** _pInterface)
	{
		if(!(*_pInterface))
		{
			(*_pInterface) = new CoreInterface_DLL();
		}
	}

	//---------------------------------------------------------------
	void __declspec(dllexport) ReleaseCoreInterface(CoreInterface** _pInterface)
	{
		if((*_pInterface))
		{
			delete (*_pInterface);
			(*_pInterface) = nullptr;
		}
	}
}