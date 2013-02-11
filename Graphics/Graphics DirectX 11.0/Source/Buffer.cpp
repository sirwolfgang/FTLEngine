//===============================================================
// File:	Buffer.cpp
// Purpose: Handle Buffer Functionality
//===============================================================
#include "Buffer.h"
using namespace Graphics;

//---------------------------------------------------------------
// BaseBuffer_DX11_0
//---------------------------------------------------------------
BaseBuffer_DX11_0::BaseBuffer_DX11_0()
	: m_pBuffer(nullptr)
{

}

//---------------------------------------------------------------
BaseBuffer_DX11_0::BaseBuffer_DX11_0(BaseBuffer_DX11_0 const& _That)
{

}

//---------------------------------------------------------------
BaseBuffer_DX11_0& BaseBuffer_DX11_0::operator=(BaseBuffer_DX11_0 const& _That)
{
	return *this;
}

//---------------------------------------------------------------
BaseBuffer_DX11_0::BaseBuffer_DX11_0(ID3D11Buffer* _pBuffer)
	: m_pBuffer(_pBuffer)
{

}

//---------------------------------------------------------------
BaseBuffer_DX11_0::~BaseBuffer_DX11_0()
{
	RELEASE_COM(m_pBuffer);
}

//---------------------------------------------------------------
// VertexBuffer
//---------------------------------------------------------------
VertexBuffer_DX11_0::VertexBuffer_DX11_0(ID3D11Buffer* _pBuffer)
	: BaseBuffer_DX11_0(_pBuffer)
{

}

//---------------------------------------------------------------
void VertexBuffer_DX11_0::SetBufferActive()
{

}