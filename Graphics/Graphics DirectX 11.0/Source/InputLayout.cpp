//===============================================================
// File:	InputLayout.h
// Purpose: Handle Vertex Input Layout
//===============================================================
#include "InputLayout.h"

//---------------------------------------------------------------
InputLayout_DX11_0::InputLayout_DX11_0()
	: m_pInputLayout(nullptr)
{

}

//---------------------------------------------------------------
InputLayout_DX11_0::InputLayout_DX11_0(ID3D11InputLayout* _pInputLayout)
	: m_pInputLayout(_pInputLayout)
{

}

//---------------------------------------------------------------
InputLayout_DX11_0::~InputLayout_DX11_0()
{
	RELEASE_COM(m_pInputLayout);
}