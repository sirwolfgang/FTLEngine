//===============================================================
// File:	Renderer.inl
// Purpose: Act as the direct Rendering Interface
//===============================================================

//---------------------------------------------------------------
// Singleton
//---------------------------------------------------------------
inline Graphics::Renderer_DX11_0* Graphics::Renderer_DX11_0::Instance()
{
	return sm_pInstance;
}

//---------------------------------------------------------------
// Device Access
//---------------------------------------------------------------
inline ID3D11Device* Graphics::Renderer_DX11_0::Device()
{
	return m_pDevice;
}

//---------------------------------------------------------------
inline ID3D11DeviceContext* Graphics::Renderer_DX11_0::DeviceContext()
{
	return m_pDeviceContext;
}