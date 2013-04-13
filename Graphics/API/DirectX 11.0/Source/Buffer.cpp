//===============================================================
// File:	Buffer.cpp
// Purpose: Handle Buffer Functionality
//===============================================================
#include "Buffer.h"
#include "Renderer.h"
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
void BaseBuffer_DX11_0::UpdateBuffer(void* _pData)
{
	Renderer_DX11_0::Instance()->UpdateBuffer(this, _pData);
}

//---------------------------------------------------------------
// VertexBuffer
//---------------------------------------------------------------
VertexBuffer_DX11_0::VertexBuffer_DX11_0(ID3D11Buffer* _pBuffer, VertexFormat_DX11_0* _pVertexFormat)
	: BaseBuffer_DX11_0(_pBuffer),
	m_pVertexFormat(_pVertexFormat)
{

}

//---------------------------------------------------------------
void VertexBuffer_DX11_0::SetBufferActive()
{
	Renderer_DX11_0::Instance()->SetVertexBufferActive(this);
}

//---------------------------------------------------------------
// IndexBuffer
//---------------------------------------------------------------
IndexBuffer_DX11_0::IndexBuffer_DX11_0(ID3D11Buffer* _pBuffer)
	: BaseBuffer_DX11_0(_pBuffer)
{

}

//---------------------------------------------------------------
void IndexBuffer_DX11_0::SetBufferActive()
{
	Renderer_DX11_0::Instance()->SetIndexBufferActive(this);
}