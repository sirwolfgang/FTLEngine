//===============================================================
// File:	Buffer.h
// Purpose: Handle Buffer Functionality
//===============================================================
#pragma once
#include <FTLGraphicsLibrary.h>
#include "DirectX.h"
#include "VertexFormat.h"

// Disable BaseBuffer_DX11_0::UpdateBuffer dominance inherited warning 
// 'using' should overide it, warning when 'using' said to be vc++ bug
#pragma warning(disable: 4250) 

namespace Graphics
{
	//---------------------------------------------------------------
	// BaseBuffer_DX11_0
	//---------------------------------------------------------------
	class BaseBuffer_DX11_0 : public virtual IBuffer
	{
		ID3D11Buffer* m_pBuffer;

		BaseBuffer_DX11_0();
		BaseBuffer_DX11_0(BaseBuffer_DX11_0 const& _That);
		BaseBuffer_DX11_0& operator=(BaseBuffer_DX11_0 const& _That);

	public:
		BaseBuffer_DX11_0(ID3D11Buffer* _pBuffer);
		virtual ~BaseBuffer_DX11_0();

		virtual eBUFFER_TYPES	GetBufferType() = 0;
		virtual void			UpdateBuffer(void* _pData);

		ID3D11Buffer*			GetBuffer();
	};

	//---------------------------------------------------------------
	// VertexBuffer
	//---------------------------------------------------------------
	class VertexBuffer_DX11_0 : public BaseBuffer_DX11_0, public virtual VertexBuffer
	{
		using BaseBuffer_DX11_0::UpdateBuffer;

		VertexFormat_DX11_0* m_pVertexFormat;

	public:
		VertexBuffer_DX11_0(ID3D11Buffer* _pBuffer, VertexFormat_DX11_0* _pVertexFormat);
		virtual ~VertexBuffer_DX11_0();

		VertexFormat_DX11_0*	GetVertexFormat();
		virtual eBUFFER_TYPES	GetBufferType();

		virtual void			SetBufferActive();
		virtual void			SetActive();
	};

	//---------------------------------------------------------------
	// IndexBuffer
	//---------------------------------------------------------------
	class IndexBuffer_DX11_0 : public BaseBuffer_DX11_0, public virtual IndexBuffer
	{
		using BaseBuffer_DX11_0::UpdateBuffer;

	public:
		IndexBuffer_DX11_0(ID3D11Buffer* _pBuffer);
		virtual ~IndexBuffer_DX11_0();

		virtual eBUFFER_TYPES	GetBufferType();

		virtual void			SetBufferActive();
		virtual void			SetActive();
	};

	//---------------------------------------------------------------
	// ConstantBuffer
	//---------------------------------------------------------------
	class ConstantBuffer_DX11_0 : public BaseBuffer_DX11_0, public virtual ConstantBuffer
	{
		using BaseBuffer_DX11_0::UpdateBuffer;

		Shader::eSHADER_TYPES m_eShaderType;

	public:
		ConstantBuffer_DX11_0(ID3D11Buffer* _pBuffer, Shader::eSHADER_TYPES _eShaderType);
		virtual ~ConstantBuffer_DX11_0();

		Shader::eSHADER_TYPES	GetShaderType();
		virtual eBUFFER_TYPES	GetBufferType();

		virtual void			SetBufferActive();
		virtual void			SetActive();
	};
};

#include "Buffer.inl"