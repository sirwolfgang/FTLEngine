//===============================================================
// File:	Buffer.cpp
// Purpose: Handle Buffer Functionality
//===============================================================
#include "Buffer.h"
using namespace Graphics;

//---------------------------------------------------------------
// BaseBuffer
//---------------------------------------------------------------
BaseBuffer::BaseBuffer()
	: m_pBuffer(nullptr)
{

}

//---------------------------------------------------------------
BaseBuffer::BaseBuffer(BaseBuffer const& _That)
{

}

//---------------------------------------------------------------
BaseBuffer& BaseBuffer::operator=(BaseBuffer const& _That)
{
	return *this;
}

//---------------------------------------------------------------
BaseBuffer::BaseBuffer(ID3D11Buffer* _pBuffer)
	: m_pBuffer(_pBuffer)
{

}

//---------------------------------------------------------------
BaseBuffer::~BaseBuffer()
{
	RELEASE_COM(m_pBuffer);
}

//---------------------------------------------------------------
// VertexBuffer
//---------------------------------------------------------------
VertexBuffer_DX11_0::VertexBuffer_DX11_0(ID3D11Buffer* _pBuffer)
	: BaseBuffer(_pBuffer)
{

}

//---------------------------------------------------------------
void VertexBuffer_DX11_0::SetBufferActive()
{

}