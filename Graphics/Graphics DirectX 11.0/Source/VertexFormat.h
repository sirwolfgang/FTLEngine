//===============================================================
// File:	VertexFormat.h
// Purpose: To Handle Vertex Formats
//===============================================================
#pragma once
#include <FTLGraphics.h>
#include "DirectX.h"

namespace Graphics
{
	class VertexFormat_DX11_0 : public VertexFormat
	{
		D3D11_INPUT_ELEMENT_DESC	m_VertexFormat[D3D11_VS_INPUT_REGISTER_COUNT];
		uint32						m_VertexFormatLength;
		uint32						m_VertexSize;

		VertexFormat_DX11_0();
	public:
		VertexFormat_DX11_0(VertDataPair _VertexFormatArray[], uint32 _nLength);
		virtual ~VertexFormat_DX11_0();

		void	SetVertexFormatActive();
		uint32	GetVertexSize();
	};
}

#include "VertexFormat.inl"