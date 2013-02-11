//===============================================================
// File:	VertexFormat.h
// Purpose: To Handle Vertex Formats
//===============================================================
#pragma once
#include <FTLPlatform.h>

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
			eDATASIZES_UINT1,
			eDATASIZES_UINT2,
			eDATASIZES_UINT3,
			eDATASIZES_UINT4,
			eDATASIZES_INT1,
			eDATASIZES_INT2,
			eDATASIZES_INT3,
			eDATASIZES_INT4,
			eDATASIZES_QUANTITY,
		};

		struct VertDataPair
		{
			eSemantics Semantic;
			eDataSizes DataSize;
		};

		virtual ~VertexFormat() = 0;

		virtual void	SetVertexFormatActive() = 0;
		virtual uint32	GetVertexSize()			= 0;
	};

	typedef Platform::Handle<VertexFormat> HVertexFormat;
}

#include "VertexFormat.inl"