//===============================================================
// File:	WindowModule.cpp
// Purpose: To Handle the Platform Layer Window Rendering
//===============================================================
#include "WindowModule.h"
using namespace Core;

WindowModule::WindowModule() : m_Window()
{

}

//---------------------------------------------------------------
WindowModule::~WindowModule()
{

}

//---------------------------------------------------------------
void WindowModule::Initialize(InitializationData& _InitializationData)
{
	m_Window.Initialize(_InitializationData.hInstance, _InitializationData.nCmdShow);
}

//---------------------------------------------------------------
void WindowModule::Startup()
{
	// TODO:: Settings
	m_Window.Create(Platform::Window::eWindow_Mode_Normal, L"FTL Engine", 0, 0, 1024, 768);
}

//---------------------------------------------------------------
void WindowModule::Shutdown()
{
	m_Window.Destroy();
}

//---------------------------------------------------------------
void WindowModule::Update(float32 _fTime)
{
	// TODO:: Handle Error
	m_Window.Update();
}