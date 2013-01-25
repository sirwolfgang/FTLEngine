//===============================================================
// File:	VertexBuffer.h
// Purpose: Handle Vertex Buffer Functionality
//===============================================================
#pragma once
#include "VertexFormat.h"

namespace Graphics
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = 0;
	};
};

#include "VertexBuffer.inl"