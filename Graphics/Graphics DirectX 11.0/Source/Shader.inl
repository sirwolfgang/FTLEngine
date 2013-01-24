//===============================================================
// File:	Shader.inl
// Purpose: Handle Shader Wrapping
//===============================================================

//---------------------------------------------------------------
// ComputeShader
//---------------------------------------------------------------
inline Graphics::ComputeShader::eSHADER_TYPES Graphics::ComputeShader::GetShaderType()
{
	return eSHADER_TYPE_COMPUTE;
}

//---------------------------------------------------------------
// DomainShader
//---------------------------------------------------------------
inline Graphics::DomainShader::eSHADER_TYPES Graphics::DomainShader::GetShaderType()
{
	return eSHADER_TYPE_DOMAIN;
}

//---------------------------------------------------------------
// GeometryShader
//---------------------------------------------------------------
inline Graphics::GeometryShader::eSHADER_TYPES Graphics::GeometryShader::GetShaderType()
{
	return eSHADER_TYPE_GEOMETRY;
}

//---------------------------------------------------------------
// HullShader
//---------------------------------------------------------------
inline Graphics::HullShader::eSHADER_TYPES Graphics::HullShader::GetShaderType()
{
	return eSHADER_TYPE_HULL;
}

//---------------------------------------------------------------
// PixelShader
//---------------------------------------------------------------
inline Graphics::PixelShader::eSHADER_TYPES Graphics::PixelShader::GetShaderType()
{
	return eSHADER_TYPE_PIXEL;
}

//---------------------------------------------------------------
// VertexShader
//---------------------------------------------------------------
inline Graphics::VertexShader::eSHADER_TYPES Graphics::VertexShader::GetShaderType()
{
	return eSHADER_TYPE_VERTEX;
}