//===============================================================
// File:	VertexBuffer.cpp
// Purpose: Handle Vertex Buffer Functionality
//===============================================================
#include "VertexBuffer.h"
#include "Renderer.h"
using namespace Graphics;

//---------------------------------------------------------------
VertexBuffer_DX11_0::VertexBuffer_DX11_0()
{
	m_pBuffer = nullptr;
	m_pFormat = nullptr;
}

//---------------------------------------------------------------
VertexBuffer_DX11_0::VertexBuffer_DX11_0(uint32 _nBufferSize, void* _pData, VertexFormat* _pFormat)
{
	m_pBuffer = nullptr;
	m_pFormat = (VertexFormat_DX11_0*)_pFormat;

	D3D11_BUFFER_DESC BufferDescription;
	ZeroMemory(&BufferDescription, sizeof(BufferDescription));

	BufferDescription.Usage				= D3D11_USAGE_DEFAULT;
	BufferDescription.ByteWidth			= _nBufferSize;
	BufferDescription.BindFlags			= D3D11_BIND_VERTEX_BUFFER;
	BufferDescription.CPUAccessFlags	= NULL;
	BufferDescription.MiscFlags			= NULL;

	ID3D11Buffer* pBuffer;
	Renderer_DX11_0::Instance()->Device()->CreateBuffer(&BufferDescription, NULL, &pBuffer);

	D3D11_MAPPED_SUBRESOURCE MappedResouce;
	Renderer_DX11_0::Instance()->DeviceContext()->Map(pBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &MappedResouce);
	memcpy_s(MappedResouce.pData, _nBufferSize, _pData, _nBufferSize);
	Renderer_DX11_0::Instance()->DeviceContext()->Unmap(pBuffer, NULL);
}

//---------------------------------------------------------------
VertexBuffer_DX11_0::~VertexBuffer_DX11_0()
{
	RELEASE_COM(m_pBuffer);
}

//---------------------------------------------------------------
void VertexBuffer_DX11_0::SetVertexBufferActive()
{
	m_pFormat->SetVertexFormatActive();

	UINT stride = m_pFormat->GetVertexSize();
	UINT offset = 0;
	Renderer_DX11_0::Instance()->DeviceContext()->IASetVertexBuffers(NULL, 1, &m_pBuffer, &stride, &offset);
}