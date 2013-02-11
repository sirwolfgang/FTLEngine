//===============================================================
// File:	Buffer.inl
// Purpose: Handle Buffer Functionality
//===============================================================

//---------------------------------------------------------------
// BaseBuffer
//---------------------------------------------------------------
inline ID3D11Buffer* Graphics::BaseBuffer::GetBuffer()
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
