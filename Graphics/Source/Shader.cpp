//===============================================================
// File:	Shader.cpp
// Purpose: To handle wrapping of Shaders
//===============================================================
#include "Shader.h"
using namespace Graphics;

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