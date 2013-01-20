//===============================================================
// File:	Shader.cpp
// Purpose: To handle wrapping of Shaders
//===============================================================
#include "Shader.h"
using namespace Graphics;

//---------------------------------------------------------------
// Shader
//---------------------------------------------------------------
Shader::Shader()
{

}

//---------------------------------------------------------------
Shader::~Shader()
{

}

//---------------------------------------------------------------
void Shader::SetShaderActive()
{

}

//---------------------------------------------------------------
// ComputeShader
//---------------------------------------------------------------
ComputeShader::ComputeShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
ComputeShader::~ComputeShader()
{
	if(m_pShader)
	{
		m_pShader->Release();
		m_pShader = nullptr;
	}
}

//---------------------------------------------------------------
void ComputeShader::SetShaderActive()
{

}

//---------------------------------------------------------------
// DomainShader
//---------------------------------------------------------------
DomainShader::DomainShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
DomainShader::~DomainShader()
{
	if(m_pShader)
	{
		m_pShader->Release();
		m_pShader = nullptr;
	}
}

//---------------------------------------------------------------
void DomainShader::SetShaderActive()
{

}

//---------------------------------------------------------------
// GeometryShader
//---------------------------------------------------------------
GeometryShader::GeometryShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
GeometryShader::~GeometryShader()
{
	if(m_pShader)
	{
		m_pShader->Release();
		m_pShader = nullptr;
	}
}

//---------------------------------------------------------------
void GeometryShader::SetShaderActive()
{

}

//---------------------------------------------------------------
// HullShader
//---------------------------------------------------------------
HullShader::HullShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
HullShader::~HullShader()
{
	if(m_pShader)
	{
		m_pShader->Release();
		m_pShader = nullptr;
	}
}

//---------------------------------------------------------------
void HullShader::SetShaderActive()
{

}

//---------------------------------------------------------------
// PixelShader
//---------------------------------------------------------------
PixelShader::PixelShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
PixelShader::~PixelShader()
{
	if(m_pShader)
	{
		m_pShader->Release();
		m_pShader = nullptr;
	}
}

//---------------------------------------------------------------
void PixelShader::SetShaderActive()
{

}

//---------------------------------------------------------------
// VertexShader
//---------------------------------------------------------------
VertexShader::VertexShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
VertexShader::~VertexShader()
{
	if(m_pShader)
	{
		m_pShader->Release();
		m_pShader = nullptr;
	}
}

//---------------------------------------------------------------
void VertexShader::SetShaderActive()
{

}