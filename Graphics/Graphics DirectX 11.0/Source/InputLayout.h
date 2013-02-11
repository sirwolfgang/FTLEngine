//===============================================================
// File:	InputLayout.h
// Purpose: Handle Vertex Input Layout
//===============================================================
#pragma once
#include "DirectX.h"

class InputLayout_DX11_0
{
	ID3D11InputLayout* m_pInputLayout;

	InputLayout_DX11_0();
public:
	InputLayout_DX11_0(ID3D11InputLayout* _pInputLayout);
	~InputLayout_DX11_0();

	ID3D11InputLayout* GetInputLayout() { return m_pInputLayout; }
};