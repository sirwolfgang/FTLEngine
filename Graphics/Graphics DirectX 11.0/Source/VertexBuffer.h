//===============================================================
// File:	VertexBuffer.h
// Purpose: Handle Vertex Buffer Functionality
//===============================================================
#pragma once
#include <FTLGraphics.h>
#include "DirectX.h"

namespace Graphics
{
	class VertexBuffer_DX11_0 : public VertexBuffer
	{
		ID3D11Buffer* m_pBuffer; 
		VertexFormat* m_pFormat;

		VertexBuffer_DX11_0();
	public:
		VertexBuffer_DX11_0(ID3D11Buffer* _pBuffer);
		virtual ~VertexBuffer_DX11_0();
	};
};