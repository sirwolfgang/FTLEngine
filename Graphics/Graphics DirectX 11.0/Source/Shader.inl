//===============================================================
// File:	Shader.inl
// Purpose: To handle wrapping of Shaders
//===============================================================

//---------------------------------------------------------------
// Shader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::Shader::GetShaderType()
{
	return eShaderType_Unspecified;
}

//---------------------------------------------------------------
// ComputeShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::ComputeShader::GetShaderType()
{
	return eShaderType_Compute;
}

//---------------------------------------------------------------
// DomainShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::DomainShader::GetShaderType()
{
	return eShaderType_Domain;
}

//---------------------------------------------------------------
// GeometryShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::GeometryShader::GetShaderType()
{
	return eShaderType_Geometry;
}

//---------------------------------------------------------------
// HullShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::HullShader::GetShaderType()
{
	return eShaderType_Hull;
}

//---------------------------------------------------------------
// PixelShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::PixelShader::GetShaderType()
{
	return eShaderType_Pixel;
}

//---------------------------------------------------------------
// VertexShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::VertexShader::GetShaderType()
{
	return eShaderType_Vertex;
}