//===============================================================
// File:	Handle.h
// Purpose: To handle the handles that handle pointers.
//===============================================================
#pragma once

namespace Platform
{
	template <typename Type>
	class Handle
	{
		friend class HandleManager;
		HandleManager*	m_pManager;
		memsize			m_nIndex;
		uint32			m_nUsageID;

	public:
		Handle();
		Handle(Handle const& _That);
		~Handle();

		Type*	RetrieveEntry();
		uint32	GetReferenceCount();

		Handle&	operator=(Handle const& _That);
		Type*	operator->();
		Type&	operator*();
	};
};

#include "Handle.inl"