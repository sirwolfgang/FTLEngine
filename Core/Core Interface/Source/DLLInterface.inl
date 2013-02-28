//===============================================================
// File:	DLLInterface.inl
// Purpose: Handle DLL Interfacing
//===============================================================
inline Engine::Core* Engine::CoreDLL::GetCore()
{
	return m_pCore;
}

//---------------------------------------------------------------
inline HMODULE Engine::CoreDLL::GetModule()
{
	return m_hDLL;
}
