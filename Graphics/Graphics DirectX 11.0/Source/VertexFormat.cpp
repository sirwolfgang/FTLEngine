//===============================================================
// File:	VertexFormat.cpp
// Purpose: To Handle Vertex Formats
//===============================================================
#include "VertexFormat.h"
#include "Renderer.h"
using namespace Graphics;

//---------------------------------------------------------------
VertexFormat_DX11_0::VertexFormat_DX11_0()
{
	memset(m_VertexFormat, NULL, sizeof(m_VertexFormat));
	m_VertexElements		= NULL;
	m_VertexSize			= NULL;
}

//---------------------------------------------------------------
VertexFormat_DX11_0::VertexFormat_DX11_0(VertDataPair _VertexFormatArray[], uint32 _nElements)
{
	memset(m_VertexFormat, NULL, sizeof(m_VertexFormat));
	m_VertexElements		= _nElements;
	m_VertexSize			= NULL;

	for(memsize i = 0; i < m_VertexElements; ++i)
	{
		// SemanticName
		switch (_VertexFormatArray[i].Semantic)
		{
		case eSEMANTICS_POSITION:		{ m_VertexFormat[i].SemanticName = "POSITION";		} break;
		case eSEMANTICS_NORMAL:			{ m_VertexFormat[i].SemanticName = "NORMAL";		} break;
		case eSEMANTICS_TANGENT:		{ m_VertexFormat[i].SemanticName = "TANGENT";		} break;
		case eSEMANTICS_BINORMAL:		{ m_VertexFormat[i].SemanticName = "BINORMAL";		} break;
		case eSEMANTICS_TEXCOORD:		{ m_VertexFormat[i].SemanticName = "TEXCOORD";		} break;
		case eSEMANTICS_COLOR:			{ m_VertexFormat[i].SemanticName = "COLOR";			} break;
		case eSEMANTICS_BLENDINDICES:	{ m_VertexFormat[i].SemanticName = "BLENDINDICES";	} break;
		case eSEMANTICS_BLENDWEIGHT:	{ m_VertexFormat[i].SemanticName = "BLENDWEIGHT";	} break;
		case eSEMANTICS_FOGCOORD:		{ m_VertexFormat[i].SemanticName = "FOGCOORD";		} break;
		case eSEMANTICS_PSIZE:			{ m_VertexFormat[i].SemanticName = "PSIZE";			} break;
		case eSEMANTICS_NONE:
		default:						{ m_VertexFormat[i].SemanticName = "";				} break;
		}

		// SemanticIndex
		// TODO:: Handle Multiables
		m_VertexFormat[i].SemanticIndex = 0;

		// Format
		switch (_VertexFormatArray[i].DataSize)
		{
		case eDATASIZES_FLOAT1:		{ m_VertexSize += sizeof(float32)	* 1;	m_VertexFormat[i].Format = DXGI_FORMAT_R32_FLOAT;				} break;
		case eDATASIZES_FLOAT2:		{ m_VertexSize += sizeof(float32)	* 2;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32_FLOAT;			} break;
		case eDATASIZES_FLOAT3:		{ m_VertexSize += sizeof(float32)	* 3;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32B32_FLOAT;			} break;
		case eDATASIZES_FLOAT4:		{ m_VertexSize += sizeof(float32)	* 4;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;		} break;
		case eDATASIZES_UINT1:		{ m_VertexSize += sizeof(uint32)	* 1;	m_VertexFormat[i].Format = DXGI_FORMAT_R32_UINT;				} break;
		case eDATASIZES_UINT2:		{ m_VertexSize += sizeof(uint32)	* 2;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32_UINT;				} break;
		case eDATASIZES_UINT3:		{ m_VertexSize += sizeof(uint32)	* 3;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32B32_UINT;			} break;
		case eDATASIZES_UINT4:		{ m_VertexSize += sizeof(uint32)	* 4;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32B32A32_UINT;		} break;
		case eDATASIZES_INT1:		{ m_VertexSize += sizeof(int32)		* 1;	m_VertexFormat[i].Format = DXGI_FORMAT_R32_SINT;				} break;
		case eDATASIZES_INT2:		{ m_VertexSize += sizeof(int32)		* 2;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32_SINT;				} break;
		case eDATASIZES_INT3:		{ m_VertexSize += sizeof(int32)		* 3;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32B32_SINT;			} break;
		case eDATASIZES_INT4:		{ m_VertexSize += sizeof(int32)		* 4;	m_VertexFormat[i].Format = DXGI_FORMAT_R32G32B32A32_SINT;		} break;
		}

		// InputSlot
		m_VertexFormat[i].InputSlot = NULL;

		// AlignedByteOffset
		m_VertexFormat[i].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;

		// InputSlotClass
		m_VertexFormat[i].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;

		// InstanceDataStepRate
		m_VertexFormat[i].InstanceDataStepRate = NULL;
	}
}

//---------------------------------------------------------------
VertexFormat_DX11_0::~VertexFormat_DX11_0()
{

}

//---------------------------------------------------------------
void VertexFormat_DX11_0::SetVertexFormatActive()
{
	Renderer_DX11_0::Instance()->SetVertexFormatActive(this);
}