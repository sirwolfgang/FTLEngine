//===============================================================
// File:	Shader.cpp
// Purpose: Handle Shader Wrapping
//===============================================================
#include "Shader.h"
using namespace Graphics;

//---------------------------------------------------------------
// ComputeShader
//---------------------------------------------------------------
ComputeShader::ComputeShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
ComputeShader::ComputeShader(ID3D11ComputeShader* _pShader)
{
	m_pShader = _pShader;
}

//---------------------------------------------------------------
ComputeShader::~ComputeShader()
{
	RELEASE_COM(m_pShader);
}

//---------------------------------------------------------------
// DomainShader
//---------------------------------------------------------------
DomainShader::DomainShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
DomainShader::DomainShader(ID3D11DomainShader* _pShader)
{
	m_pShader = _pShader;
}

//---------------------------------------------------------------
DomainShader::~DomainShader()
{
	RELEASE_COM(m_pShader);
}

//---------------------------------------------------------------
// GeometryShader
//---------------------------------------------------------------
GeometryShader::GeometryShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
GeometryShader::GeometryShader(ID3D11GeometryShader* _pShader)
{
	m_pShader = _pShader;
}

//---------------------------------------------------------------
GeometryShader::~GeometryShader()
{
	RELEASE_COM(m_pShader);
}

//---------------------------------------------------------------
// HullShader
//---------------------------------------------------------------
HullShader::HullShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
HullShader::HullShader(ID3D11HullShader* _pShader)
{
	m_pShader = _pShader;
}

//---------------------------------------------------------------
HullShader::~HullShader()
{
	RELEASE_COM(m_pShader);
}

//---------------------------------------------------------------
// PixelShader
//---------------------------------------------------------------
PixelShader::PixelShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
PixelShader::PixelShader(ID3D11PixelShader* _pShader)
{
	m_pShader = _pShader;
}

//---------------------------------------------------------------
PixelShader::~PixelShader()
{
	RELEASE_COM(m_pShader);
}

//---------------------------------------------------------------
// VertexShader
//---------------------------------------------------------------
VertexShader::VertexShader()
{
	m_pShader = nullptr;
}

//---------------------------------------------------------------
VertexShader::VertexShader(ID3D11VertexShader* _pShader)
{
	m_pShader = _pShader;
}

//---------------------------------------------------------------
VertexShader::~VertexShader()
{
	RELEASE_COM(m_pShader);
}