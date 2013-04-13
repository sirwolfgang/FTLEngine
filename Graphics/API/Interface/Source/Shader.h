//===============================================================
// File:	Shader.h
// Purpose: Handle Shader Wrapping
//===============================================================
#pragma once
#include <FTLPlatform.h>
using Platform::Handle;

namespace Graphics
{
	class Shader
	{
	public:
		enum eSHADER_TYPES
		{
			eSHADER_TYPE_COMPUTE,
			eSHADER_TYPE_DOMAIN,
			eSHADER_TYPE_GEOMETRY,
			eSHADER_TYPE_HULL,
			eSHADER_TYPE_PIXEL,
			eSHADER_TYPE_VERTEX,
		};

		virtual ~Shader() = 0;

		virtual eSHADER_TYPES	GetShaderType() = 0;
		virtual void			SetShaderActive() = 0;
	};

	typedef Handle<Shader>	HShader;
	typedef HShader			HComputeShader;
	typedef HShader			HDomainShader;
	typedef HShader			HGeometryShader;
	typedef HShader			HHullShader;
	typedef HShader			HPixelShader;
	typedef HShader			HVertexShader;
}

#include "Shader.inl"