//===============================================================
// File:	WindowModule.cpp
// Purpose: To Handle the base module managment interface
//===============================================================
#include "WindowModule.h"
#include "../Engine.h"
using namespace Core;

//---------------------------------------------------------------
WindowModule::WindowModule()
{
	m_pWindow = new Platform::Window(Engine::Global()->hInstance(), Engine::Global()->nCmdShow());
}

//---------------------------------------------------------------
WindowModule::~WindowModule()
{
	// TODO:: Error, Wasnt Shutdown
	if(m_pWindow)
	{
		delete m_pWindow;
		m_pWindow = nullptr;
	}
}

//---------------------------------------------------------------
void WindowModule::Startup()
{
	// TODO:: Handle Dynamic Settings
	m_pWindow->Create(Platform::Window::eWindow_Mode_Normal, L"FTL Engine", 0, 0, 1024, 768);
}

//---------------------------------------------------------------
void WindowModule::Shutdown()
{
	m_pWindow->Destroy();
}

//---------------------------------------------------------------
void WindowModule::Update(float32 _fTime)
{
	// TODO:: Handle Exit Event
	m_pWindow->Update();
}