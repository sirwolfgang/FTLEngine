//===============================================================
// File:	Shader.inl
// Purpose: To handle wrapping of Shaders
//===============================================================

//---------------------------------------------------------------
// VertexShader
//---------------------------------------------------------------
inline Graphics::VertexShader::eShaderType Graphics::VertexShader::GetShaderType()
{
	return eShaderType_Vertex;
}

//---------------------------------------------------------------
// PixelShader
//---------------------------------------------------------------
inline Graphics::PixelShader::eShaderType Graphics::PixelShader::GetShaderType()
{
	return eShaderType_Pixel;
}

//---------------------------------------------------------------
// GeometryShader
//---------------------------------------------------------------
inline Graphics::GeometryShader::eShaderType Graphics::GeometryShader::GetShaderType()
{
	return eShaderType_Geometry;
}