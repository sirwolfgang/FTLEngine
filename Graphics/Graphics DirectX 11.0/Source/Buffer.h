//===============================================================
// File:	Buffer.h
// Purpose: Handle Buffer Functionality
//===============================================================
#pragma once
#include <FTLGraphics.h>
#include "DirectX.h"
#include "VertexFormat.h"

namespace Graphics
{
	//---------------------------------------------------------------
	// BaseBuffer_DX11_0
	//---------------------------------------------------------------
	class BaseBuffer_DX11_0 : public Buffer
	{
		ID3D11Buffer* m_pBuffer;
	
		BaseBuffer_DX11_0();
		BaseBuffer_DX11_0(BaseBuffer_DX11_0 const& _That);
		BaseBuffer_DX11_0& operator=(BaseBuffer_DX11_0 const& _That);
		
	public:
		BaseBuffer_DX11_0(ID3D11Buffer* _pBuffer);
		virtual ~BaseBuffer_DX11_0();
	
		virtual eBUFFER_TYPES	GetBufferType()		= 0;
		virtual void			SetBufferActive()	= 0;
	
		ID3D11Buffer*			GetBuffer();
	};

	//---------------------------------------------------------------
	// VertexBuffer
	//---------------------------------------------------------------
	class VertexBuffer_DX11_0 : public BaseBuffer_DX11_0
	{
		VertexFormat_DX11_0* m_pVertexFormat;

	public:
		VertexBuffer_DX11_0(ID3D11Buffer* _pBuffer, VertexFormat_DX11_0* _pVertexFormat);

		VertexFormat_DX11_0*	GetVertexFormat();
		virtual eBUFFER_TYPES	GetBufferType();
		virtual void			SetBufferActive();
	};
};

#include "Buffer.inl"