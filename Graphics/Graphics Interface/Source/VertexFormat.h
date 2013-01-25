//===============================================================
// File:	VertexFormat.h
// Purpose: To Handle Vertex Formats
//===============================================================
#pragma once

namespace Graphics
{
	class VertexFormat
	{
	public:
		enum eSemantics
		{
			eSEMANTICS_NONE,
			eSEMANTICS_POSITION,
			eSEMANTICS_NORMAL,
			eSEMANTICS_TANGENT,
			eSEMANTICS_BINORMAL,
			eSEMANTICS_TEXCOORD,
			eSEMANTICS_COLOR,
			eSEMANTICS_BLENDINDICES,
			eSEMANTICS_BLENDWEIGHT,
			eSEMANTICS_FOGCOORD,
			eSEMANTICS_PSIZE,
			eSEMANTICS_QUANTITY,
		};

		enum eDataSizes
		{
			eDATASIZES_NONE,
			eDATASIZES_FLOAT1,
			eDATASIZES_FLOAT2,
			eDATASIZES_FLOAT3,
			eDATASIZES_FLOAT4,
			eDATASIZES_HALF1,
			eDATASIZES_HALF2,
			eDATASIZES_HALF3,
			eDATASIZES_HALF4,
			eDATASIZES_UBYTE4,
			eDATASIZES_SHORT1,
			eDATASIZES_SHORT2,
			eDATASIZES_SHORT4,
			eDATASIZES_QUANTITY,
		};

		virtual ~VertexFormat() = 0;
	};
}

#include "VertexFormat.inl"