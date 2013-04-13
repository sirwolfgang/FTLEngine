//===============================================================
// File:	DLLInterface.inl
// Purpose: Handle DLL Interfacing
//===============================================================
inline Graphics::Renderer* Graphics::RendererDLL::GetRenderer()
{
	return m_pRenderer;
}

//---------------------------------------------------------------
inline HMODULE Graphics::RendererDLL::GetModule()
{
	return m_hDLL;
}
