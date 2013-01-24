//===============================================================
// File:	Shader.h
// Purpose: Handle Shader Wrapping
//===============================================================
#pragma once
#include <FTLGraphics.h>
#include "DirectX.h"

namespace Graphics
{
	//---------------------------------------------------------------
	// ComputeShader
	//---------------------------------------------------------------
	class ComputeShader : public Shader
	{
		ID3D11ComputeShader* m_pShader;

		ComputeShader();
	public:
		ComputeShader(ID3D11ComputeShader* _pShader);
		virtual ~ComputeShader();

		virtual eSHADER_TYPES GetShaderType();
	};

	//---------------------------------------------------------------
	// DomainShader
	//---------------------------------------------------------------
	class DomainShader : public Shader
	{
		ID3D11DomainShader* m_pShader;

		DomainShader();
	public:
		DomainShader(ID3D11DomainShader* _pShader);
		virtual ~DomainShader();

		virtual eSHADER_TYPES GetShaderType();
	};

	//---------------------------------------------------------------
	// GeometryShader
	//---------------------------------------------------------------
	class GeometryShader : public Shader
	{		
		ID3D11GeometryShader* m_pShader;

		GeometryShader();
	public:
		GeometryShader(ID3D11GeometryShader* _pShader);
		virtual ~GeometryShader();

		virtual eSHADER_TYPES GetShaderType();
	};

	//---------------------------------------------------------------
	// HullShader
	//---------------------------------------------------------------
	class HullShader : public Shader
	{
		ID3D11HullShader* m_pShader;

		HullShader();
	public:
		HullShader(ID3D11HullShader* _pShader);
		virtual ~HullShader();

		virtual eSHADER_TYPES GetShaderType();
	};

	//---------------------------------------------------------------
	// PixelShader
	//---------------------------------------------------------------
	class PixelShader : public Shader
	{
		ID3D11PixelShader* m_pShader;

		PixelShader();
	public:
		PixelShader(ID3D11PixelShader* _pShader);
		virtual ~PixelShader();

		virtual eSHADER_TYPES GetShaderType();
	};

	//---------------------------------------------------------------
	// VertexShader
	//---------------------------------------------------------------
	class VertexShader : public Shader
	{
		ID3D11VertexShader* m_pShader;

		VertexShader();
	public:
		VertexShader(ID3D11VertexShader* _pShader);
		virtual ~VertexShader();

		virtual eSHADER_TYPES GetShaderType();
	};
}

#include "Shader.inl"