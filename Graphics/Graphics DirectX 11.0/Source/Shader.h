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
	// BaseShader_DX11_0
	//---------------------------------------------------------------
	template <typename PointerType, Shader::eSHADER_TYPES ShaderType>
	class BaseShader_DX11_0 : public Shader
	{
		PointerType* m_pShader;

		BaseShader_DX11_0();
		BaseShader_DX11_0(BaseShader_DX11_0 const& _That);
		BaseShader_DX11_0& operator=(BaseShader_DX11_0 const& _That);
		
	public:
		BaseShader_DX11_0(PointerType* _pShader);
		virtual ~BaseShader_DX11_0();

		virtual eSHADER_TYPES	GetShaderType();
		virtual void			SetShaderActive();

		PointerType*			GetShader();
	};

	//---------------------------------------------------------------
	// Shaders
	//---------------------------------------------------------------
	typedef BaseShader_DX11_0<ID3D11ComputeShader,		Shader::eSHADER_TYPE_COMPUTE>	ComputeShader_DX11_0;
	typedef BaseShader_DX11_0<ID3D11DomainShader,		Shader::eSHADER_TYPE_DOMAIN>	DomainShader_DX11_0;
	typedef BaseShader_DX11_0<ID3D11GeometryShader,		Shader::eSHADER_TYPE_GEOMETRY>	GeometryShader_DX11_0;
	typedef BaseShader_DX11_0<ID3D11HullShader,			Shader::eSHADER_TYPE_HULL>		HullShader_DX11_0;
	typedef BaseShader_DX11_0<ID3D11PixelShader,		Shader::eSHADER_TYPE_PIXEL>		PixelShader_DX11_0;
	typedef BaseShader_DX11_0<ID3D11VertexShader,		Shader::eSHADER_TYPE_VERTEX>	VertexShader_DX11_0;

}

#include "Shader.inl"