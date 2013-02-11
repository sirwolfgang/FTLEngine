//===============================================================
// File:	Shader.inl
// Purpose: Handle Shader Wrapping
//===============================================================

template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader<PointerType, ShaderType>::BaseShader() : Shader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader<PointerType, ShaderType>::BaseShader(BaseShader const& _That)
{

}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader<PointerType, ShaderType>& Graphics::BaseShader<PointerType, ShaderType>::operator=(BaseShader const& _That)
{
	return *this;
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader<PointerType, ShaderType>::BaseShader(PointerType* _pShader) : Shader()
{
	m_pShader = _pShader;
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader<PointerType, ShaderType>::~BaseShader()
{
	RELEASE_COM(m_pShader);
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::Shader::eSHADER_TYPES Graphics::BaseShader<PointerType, ShaderType>::GetShaderType()
{
	return ShaderType;
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline void Graphics::BaseShader<PointerType, ShaderType>::SetShaderActive()
{
	Renderer_DX11_0::Instance()->SetShaderActive(this);
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline PointerType* Graphics::BaseShader<PointerType, ShaderType>::GetShader()
{
	return m_pShader;
}