//===============================================================
// File:	VertexBuffer.cpp
// Purpose: Handle Vertex Buffer Functionality
//===============================================================
#include "VertexBuffer.h"
using namespace Graphics;

//---------------------------------------------------------------
VertexBuffer_DX11_0::VertexBuffer_DX11_0()
{
	m_pBuffer = nullptr;
}

//---------------------------------------------------------------
VertexBuffer_DX11_0::VertexBuffer_DX11_0(ID3D11Buffer* _pBuffer)
{
	m_pBuffer = _pBuffer;
}

//---------------------------------------------------------------
VertexBuffer_DX11_0::~VertexBuffer_DX11_0()
{
	RELEASE_COM(m_pBuffer);
}