//===============================================================
// File:	Shader.h
// Purpose: To handle wrapping of Shaders
//===============================================================
#pragma once
#include "DLL.h"
#include "DirectX.h"

namespace Graphics
{
	//---------------------------------------------------------------
	// IShader
	//---------------------------------------------------------------
	class GRAPHICS_API IShader
	{
	public:
		enum eShaderType
		{
			eShaderType_Unspecified,
			eShaderType_Vertex,
			eShaderType_Pixel,
			eShaderType_Geometry,
		};

		virtual eShaderType GetShaderType() = 0;
	};

	//---------------------------------------------------------------
	// VertexShader
	//---------------------------------------------------------------
	class GRAPHICS_API VertexShader : public IShader
	{
		ID3D11VertexShader* m_pShader;

	public:
		virtual eShaderType GetShaderType();
	};

	//---------------------------------------------------------------
	// PixelShader
	//---------------------------------------------------------------
	class GRAPHICS_API PixelShader : public IShader
	{
		ID3D11PixelShader* m_pShader;

	public:
		virtual eShaderType GetShaderType();
	};

	//---------------------------------------------------------------
	// GeometryShader
	//---------------------------------------------------------------
	class GRAPHICS_API GeometryShader : public IShader
	{
		ID3D11GeometryShader* m_pShader;

	public:
		virtual eShaderType GetShaderType();
	};
}

#include "Shader.inl"