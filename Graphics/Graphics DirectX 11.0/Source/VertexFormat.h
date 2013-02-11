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
		uint32						m_VertexElements;
		uint32						m_VertexSize;

		VertexFormat_DX11_0();
	public:
		VertexFormat_DX11_0(VertDataPair _VertexFormatArray[], uint32 _nLength);
		virtual ~VertexFormat_DX11_0();

		virtual void	SetVertexFormatActive();
		virtual uint32	GetVertexSize();

		uint32						GetNumberElements();
		D3D11_INPUT_ELEMENT_DESC*	GetVertexFormat();
	};
}

#include "VertexFormat.inl"