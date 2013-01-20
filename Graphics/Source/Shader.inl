//===============================================================
// File:	Shader.inl
// Purpose: To handle wrapping of Shaders
//===============================================================

//---------------------------------------------------------------
// VertexShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::VertexShader::GetShaderType()
{
	return eShaderType_Vertex;
}

//---------------------------------------------------------------
// PixelShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::PixelShader::GetShaderType()
{
	return eShaderType_Pixel;
}

//---------------------------------------------------------------
// GeometryShader
//---------------------------------------------------------------
inline Graphics::eShaderType Graphics::GeometryShader::GetShaderType()
{
	return eShaderType_Geometry;
}