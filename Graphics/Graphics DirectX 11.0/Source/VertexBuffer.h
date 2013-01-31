//===============================================================
// File:	VertexBuffer.h
// Purpose: Handle Vertex Buffer Functionality
//===============================================================
#pragma once
#include <FTLGraphics.h>
#include "DirectX.h"
#include "VertexFormat.h"

namespace Graphics
{
	class VertexBuffer_DX11_0 : public VertexBuffer
	{
		ID3D11Buffer*			m_pBuffer; 
		VertexFormat_DX11_0*	m_pFormat;

		VertexBuffer_DX11_0();
	public:
		VertexBuffer_DX11_0(uint32 _nBufferSize, void* _pData, VertexFormat* _pFormat);
		virtual ~VertexBuffer_DX11_0();

		virtual void SetVertexBufferActive();
	};
};