//===============================================================
// File:	Buffer.h
// Purpose: Handle Buffer Functionality
//===============================================================
#pragma once
#include <FTLPlatform.h>
using Platform::Handle;

namespace Graphics
{
	//---------------------------------------------------------------
	// Buffer
	//---------------------------------------------------------------
	class Buffer
	{
	public:
		enum eBUFFER_TYPES
		{
			eBUFFER_TYPE_VERTEX,
			eBUFFER_TYPE_INDEX,
			eBUFFER_TYPE_CONSTANT,
		};

		virtual ~Buffer() = 0;

		virtual eBUFFER_TYPES	GetBufferType()				= 0;
		virtual void			SetBufferActive()			= 0;
		virtual void			UpdateBuffer(void* _pData)	= 0;
	};

	typedef Handle<Buffer>	HBuffer;
	typedef HBuffer			HVertexBuffer;
	typedef HBuffer			HIndexBuffer;
	typedef HBuffer			HConstantBuffer;
};

#include "Buffer.inl"