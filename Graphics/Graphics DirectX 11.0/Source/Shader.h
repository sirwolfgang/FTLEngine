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
	class IShader
	{
	public:
		virtual eShaderType GetShaderType() = 0;
		virtual void SetShaderActive()		= 0;
	};

	//---------------------------------------------------------------
	// Shader
	//---------------------------------------------------------------
	class GRAPHICS_API Shader : public IShader
	{
	public:
		Shader();
		virtual ~Shader();

		virtual eShaderType GetShaderType();
		virtual void SetShaderActive();
	};

	//---------------------------------------------------------------
	// ComputeShader
	//---------------------------------------------------------------
	class ComputeShader : public Shader
	{
		friend class Renderer;
		ID3D11ComputeShader* m_pShader;

		ComputeShader();
	public:
		virtual ~ComputeShader();

		virtual eShaderType GetShaderType();
		virtual void SetShaderActive();
	};


	//---------------------------------------------------------------
	// DomainShader
	//---------------------------------------------------------------
	class DomainShader : public Shader
	{
		friend class Renderer;
		ID3D11DomainShader* m_pShader;

		DomainShader();
	public:
		virtual ~DomainShader();

		virtual eShaderType GetShaderType();
		virtual void SetShaderActive();
	};


	//---------------------------------------------------------------
	// GeometryShader
	//---------------------------------------------------------------
	class GeometryShader : public Shader
	{
		friend class Renderer;
		ID3D11GeometryShader* m_pShader;

		GeometryShader();
	public:
		virtual ~GeometryShader();

		virtual eShaderType GetShaderType();
		virtual void SetShaderActive();
	};

	//---------------------------------------------------------------
	// HullShader
	//---------------------------------------------------------------
	class HullShader : public Shader
	{
		friend class Renderer;
		ID3D11HullShader* m_pShader;

		HullShader();
	public:
		virtual ~HullShader();

		virtual eShaderType GetShaderType();
		virtual void SetShaderActive();
	};

	//---------------------------------------------------------------
	// PixelShader
	//---------------------------------------------------------------
	class PixelShader : public Shader
	{
		friend class Renderer;
		ID3D11PixelShader* m_pShader;

		PixelShader();
	public:
		virtual ~PixelShader();

		virtual eShaderType GetShaderType();
		virtual void SetShaderActive();
	};

	//---------------------------------------------------------------
	// VertexShader
	//---------------------------------------------------------------
	class VertexShader : public Shader
	{
		friend class Renderer;
		ID3D11VertexShader* m_pShader;

		VertexShader();
	public:
		virtual ~VertexShader();

		virtual eShaderType GetShaderType();
		virtual void SetShaderActive();
	};
}

#include "Shader.inl"