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

//---------------------------------------------------------------
inline Graphics::VertexFormat_DX11_0* Graphics::VertexBuffer_DX11_0::GetVertexFormat()
{
	return m_pVertexFormat;
}

//---------------------------------------------------------------
// IndexBuffer
//---------------------------------------------------------------
inline Graphics::Buffer::eBUFFER_TYPES Graphics::IndexBuffer_DX11_0::GetBufferType()
{
	return eBUFFER_TYPE_INDEX;
}

//---------------------------------------------------------------
// ConstantBuffer
//---------------------------------------------------------------
inline Graphics::Buffer::eBUFFER_TYPES Graphics::ConstantBuffer_DX11_0::GetBufferType()
{
	return eBUFFER_TYPE_CONSTANT;
}