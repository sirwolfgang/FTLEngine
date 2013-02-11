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
	// BaseShader
	//---------------------------------------------------------------
	template <typename PointerType, Shader::eSHADER_TYPES ShaderType>
	class BaseShader : public Shader
	{
		PointerType* m_pShader;

		BaseShader();
		BaseShader(BaseShader const& _That);
		BaseShader& operator=(BaseShader const& _That);
		
	public:
		BaseShader(PointerType* _pShader);
		virtual ~BaseShader();

		virtual eSHADER_TYPES	GetShaderType();
		virtual void			SetShaderActive();

		PointerType*			GetShader();
	};

	//---------------------------------------------------------------
	// Shaders
	//---------------------------------------------------------------
	typedef BaseShader<ID3D11ComputeShader,		Shader::eSHADER_TYPE_COMPUTE>	ComputeShader;
	typedef BaseShader<ID3D11DomainShader,		Shader::eSHADER_TYPE_DOMAIN>	DomainShader;
	typedef BaseShader<ID3D11GeometryShader,	Shader::eSHADER_TYPE_GEOMETRY>	GeometryShader;
	typedef BaseShader<ID3D11HullShader,		Shader::eSHADER_TYPE_HULL>		HullShader;
	typedef BaseShader<ID3D11PixelShader,		Shader::eSHADER_TYPE_PIXEL>		PixelShader;
	typedef BaseShader<ID3D11VertexShader,		Shader::eSHADER_TYPE_VERTEX>	VertexShader;

}

#include "Shader.inl"