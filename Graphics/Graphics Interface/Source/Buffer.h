//===============================================================
// File:	Buffer.h
// Purpose: Handle Buffer Functionality
//===============================================================
#pragma once
#include <FTLPlatform.h>
using Platform::Handle;

namespace Graphics
{
	class Buffer
	{
	public:
		enum eBUFFER_TYPES
		{
			eBUFFER_TYPE_VERTEX,
			eBUFFER_TYPE_INDEX,
		};

		virtual ~Buffer() = 0;

		virtual eBUFFER_TYPES	GetBufferType()		= 0;
		virtual void			SetBufferActive()	= 0;
	};

	typedef Handle<Buffer>	HBuffer;
	typedef HBuffer			HVertexBuffer;
	typedef HBuffer			HIndexBuffer;
};

#include "Buffer.inl"