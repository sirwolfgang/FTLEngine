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
	class IBuffer
	{
	public:
		enum eBUFFER_TYPES
		{
			eBUFFER_TYPE_VERTEX,
			eBUFFER_TYPE_INDEX,
			eBUFFER_TYPE_CONSTANT,
		};

		virtual ~IBuffer() = 0;

		virtual eBUFFER_TYPES	GetBufferType()				= 0;
		virtual void			UpdateBuffer(void* _pData)	= 0;
	};

	//---------------------------------------------------------------
	// VertexBuffer
	//---------------------------------------------------------------
	class VertexBuffer : public virtual IBuffer
	{
	public:
		virtual ~VertexBuffer()			= 0;
		virtual void SetBufferActive()	= 0;
	};

	//---------------------------------------------------------------
	// IndexBuffer
	//---------------------------------------------------------------
	class IndexBuffer : public virtual IBuffer
	{
	public:
		virtual ~IndexBuffer()			= 0;
		virtual void SetBufferActive()	= 0;
	};

	//---------------------------------------------------------------
	// ConstantBuffer
	//---------------------------------------------------------------
	class ConstantBuffer : public virtual IBuffer
	{
	public:
		virtual ~ConstantBuffer()		= 0;
		virtual void SetBufferActive()	= 0;
	};

	//---------------------------------------------------------------
	// Handles
	//---------------------------------------------------------------
	typedef Handle<VertexBuffer>	HVertexBuffer;
	typedef Handle<IndexBuffer>		HIndexBuffer;
	typedef Handle<ConstantBuffer>	HConstantBuffer;
};

#include "Buffer.inl"