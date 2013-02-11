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

//---------------------------------------------------------------
// Rendering Settings
//---------------------------------------------------------------
inline uint32 Graphics::Renderer_DX11_0::GetWidth()
{
	return m_tStarupSettings.nWidth;
}

//---------------------------------------------------------------
inline uint32 Graphics::Renderer_DX11_0::GetHeight()
{
	return m_tStarupSettings.nHeight;
}

//---------------------------------------------------------------
inline uint32 Graphics::Renderer_DX11_0::GetRefreshRate()
{
	return m_tStarupSettings.nRefreshRate;
}

//---------------------------------------------------------------
inline uint32 Graphics::Renderer_DX11_0::GetMSAASamples()
{
	return m_tStarupSettings.nMSAASamples;
}

//---------------------------------------------------------------
inline uint32 Graphics::Renderer_DX11_0::GetSampleQuality()
{
	return m_tStarupSettings.nSampleQuality;
}

//---------------------------------------------------------------
inline uint32 Graphics::Renderer_DX11_0::GetBuffersCount()
{
	return m_tStarupSettings.nBufferCount;
}

//---------------------------------------------------------------
inline Graphics::Renderer_DX11_0::eDriverMode Graphics::Renderer_DX11_0::GetDriverMode()
{
	return m_tStarupSettings.eDriverMode;
}

//---------------------------------------------------------------
inline bool Graphics::Renderer_DX11_0::GetDebugMode()
{
	return m_tStarupSettings.bDebugMode;
}

//---------------------------------------------------------------
// Primitive Management
//---------------------------------------------------------------
inline Graphics::Primitive::eTOPOLOGY Graphics::Renderer_DX11_0::GetPrimitiveTopology()
{
	return m_eActivePrimitiveTopology;
}

//---------------------------------------------------------------
// View Management
//---------------------------------------------------------------
inline bool Graphics::Renderer_DX11_0::IsFullscreen()
{
	return m_bIsFullscreen;
}