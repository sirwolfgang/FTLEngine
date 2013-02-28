//===============================================================
// File:	DLLInterface.inl
// Purpose: Handle DLL Interfacing
//===============================================================
inline Core::CoreInterface* Core::CoreDLL::GetCoreInterface()
{
	return m_pCoreInterface;
}

//---------------------------------------------------------------
inline HMODULE Core::CoreDLL::GetModule()
{
	return m_hDLL;
}
