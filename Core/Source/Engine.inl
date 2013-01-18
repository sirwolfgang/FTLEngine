//===============================================================
// File:	Engine.inl
// Purpose: To handle game engine runtime, and scope
//===============================================================
inline Core::Engine* Core::Engine::Global()
{
	return sm_Instance;
}

//---------------------------------------------------------------
inline HINSTANCE Core::Engine::hInstance()
{
	return m_hInstance;
}

//---------------------------------------------------------------
inline LPSTR Core::Engine::lpCmdLine()
{
	return m_lpCmdLine;
}

//---------------------------------------------------------------
inline int32 Core::Engine::nCmdShow()
{
	return m_nCmdShow;
}