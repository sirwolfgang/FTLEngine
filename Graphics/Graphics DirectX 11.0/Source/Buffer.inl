//===============================================================
// File:	Buffer.inl
// Purpose: Handle Buffer Functionality
//===============================================================

//---------------------------------------------------------------
// BaseBuffer_DX11_0
//---------------------------------------------------------------
inline ID3D11Buffer* Graphics::BaseBuffer_DX11_0::GetBuffer()
{
	return m_pBuffer;
}

//---------------------------------------------------------------
// VertexBuffer
//---------------------------------------------------------------
inline Graphics::Buffer::eBUFFER_TYPES Graphics::VertexBuffer_DX11_0::GetBufferType()
{
	return eBUFFER_TYPE_VERTEX;
}
