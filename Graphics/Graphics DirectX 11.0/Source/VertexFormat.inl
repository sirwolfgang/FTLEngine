//===============================================================
// File:	VertexFormat.h
// Purpose: To Handle Vertex Formats
//===============================================================

inline uint32 Graphics::VertexFormat_DX11_0::GetVertexSize()
{
	return m_VertexSize;
}

//---------------------------------------------------------------
inline uint32 Graphics::VertexFormat_DX11_0::GetNumberElements()
{
	return m_VertexElements;
}

//---------------------------------------------------------------
inline D3D11_INPUT_ELEMENT_DESC* Graphics::VertexFormat_DX11_0::GetVertexFormat()
{
	return m_VertexFormat;
}