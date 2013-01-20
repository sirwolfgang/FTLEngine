//===============================================================
// File:	Shader.h
// Purpose: To handle wrapping of Shaders
//===============================================================
#pragma once
#include "DLL.h"
#include "DirectX.h"

namespace Graphics
{
	enum eShaderType
	{
		eShaderType_Unspecified,
		eShaderType_Compute,
		eShaderType_Domain,
		eShaderType_Geometry,
		eShaderType_Hull,
		eShaderType_Pixel,
		eShaderType_Vertex,
	};

	//---------------------------------------------------------------
	// IShader
	//---------------------------------------------------------------
	class GRAPHICS_API IShader
	{
	public:
		virtual eShaderType GetShaderType() = 0;
	};

	//---------------------------------------------------------------
	// VertexShader
	//---------------------------------------------------------------
	class GRAPHICS_API VertexShader : public IShader
	{
		friend class Renderer;
		ID3D11VertexShader* m_pShader;

	public:
		VertexShader();
		~VertexShader();

		virtual eShaderType GetShaderType();
	};

	//---------------------------------------------------------------
	// PixelShader
	//---------------------------------------------------------------
	class GRAPHICS_API PixelShader : public IShader
	{
		friend class Renderer;
		ID3D11PixelShader* m_pShader;

	public:
		PixelShader();
		~PixelShader();

		virtual eShaderType GetShaderType();
	};

	//---------------------------------------------------------------
	// GeometryShader
	//---------------------------------------------------------------
	class GRAPHICS_API GeometryShader : public IShader
	{
		friend class Renderer;
		ID3D11GeometryShader* m_pShader;

	public:
		GeometryShader();
		~GeometryShader();

		virtual eShaderType GetShaderType();
	};
}

#include "Shader.inl"