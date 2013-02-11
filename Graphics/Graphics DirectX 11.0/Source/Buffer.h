//===============================================================
// File:	Buffer.h
// Purpose: Handle Buffer Functionality
//===============================================================
#pragma once
#include <FTLGraphics.h>
#include "DirectX.h"

namespace Graphics
{
	//---------------------------------------------------------------
	// BaseBuffer
	//---------------------------------------------------------------
	class BaseBuffer : public Buffer
	{
		ID3D11Buffer* m_pBuffer;
	
		BaseBuffer();
		BaseBuffer(BaseBuffer const& _That);
		BaseBuffer& operator=(BaseBuffer const& _That);
		
	public:
		BaseBuffer(ID3D11Buffer* _pBuffer);
		virtual ~BaseBuffer();
	
		virtual eBUFFER_TYPES	GetBufferType()		= 0;
		virtual void			SetBufferActive()	= 0;
	
		ID3D11Buffer*			GetBuffer();
	};

	//---------------------------------------------------------------
	// VertexBuffer
	//---------------------------------------------------------------
	class VertexBuffer_DX11_0 : public BaseBuffer
	{
	public:
		VertexBuffer_DX11_0(ID3D11Buffer* _pBuffer);

		virtual eBUFFER_TYPES	GetBufferType();
		virtual void			SetBufferActive();
	};
};

#include "Buffer.inl"