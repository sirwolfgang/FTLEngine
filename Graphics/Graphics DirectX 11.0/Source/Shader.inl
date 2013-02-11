//===============================================================
// File:	Shader.inl
// Purpose: Handle Shader Wrapping
//===============================================================

template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader_DX11_0<PointerType, ShaderType>::BaseShader_DX11_0() : Shader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader_DX11_0<PointerType, ShaderType>::BaseShader_DX11_0(BaseShader_DX11_0 const& _That)
{

}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader_DX11_0<PointerType, ShaderType>& Graphics::BaseShader_DX11_0<PointerType, ShaderType>::operator=(BaseShader_DX11_0 const& _That)
{
	return *this;
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader_DX11_0<PointerType, ShaderType>::BaseShader_DX11_0(PointerType* _pShader) : Shader()
{
	m_pShader = _pShader;
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::BaseShader_DX11_0<PointerType, ShaderType>::~BaseShader_DX11_0()
{
	RELEASE_COM(m_pShader);
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline Graphics::Shader::eSHADER_TYPES Graphics::BaseShader_DX11_0<PointerType, ShaderType>::GetShaderType()
{
	return ShaderType;
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline void Graphics::BaseShader_DX11_0<PointerType, ShaderType>::SetShaderActive()
{
	Renderer_DX11_0::Instance()->SetShaderActive(this);
}

//---------------------------------------------------------------
template <typename PointerType, Graphics::Shader::eSHADER_TYPES ShaderType>
inline PointerType* Graphics::BaseShader_DX11_0<PointerType, ShaderType>::GetShader()
{
	return m_pShader;
}