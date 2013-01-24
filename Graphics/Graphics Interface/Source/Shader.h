//===============================================================
// File:	Shader.h
// Purpose: Handle Shader Wrapping
//===============================================================
#pragma once

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
}

#include "Shader.inl"