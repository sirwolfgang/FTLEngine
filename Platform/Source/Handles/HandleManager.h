//===============================================================
// File:	HandleManager.h
// Purpose: To act as a general purpose manager of handles
//===============================================================
#pragma once
#include "../DataTypes.h"
#include "../Collections/Collections.h"

namespace Platform
{
	class HandleManager
	{
		struct HandleEntry
		{
			uint32	m_nReferenceCount;
			uint32	m_nUsageID;
			void*	m_pEntry;
		};

		std::vector<HandleEntry>	m_Handles;
		std::vector<memsize_u>		m_FreeList;

		template<typename Type>
		friend class Handle;
		void*	RetrieveEntry		(memsize_u _nIndex, uint32 _nUsageID);
		void	AddReference		(memsize_u _nIndex, uint32 _nUsageID);
		uint32	GetReferenceCount	(memsize_u _nIndex, uint32 _nUsageID);
		void	ReleaseReference	(memsize_u _nIndex, uint32 _nUsageID);

	public:
		HandleManager();
		HandleManager(HandleManager const& _That);
		~HandleManager();

		HandleManager& operator=(HandleManager const& _That);

		template<typename Type>
		Handle<Type> CreateHandle(Type* _pEntry);

		template<typename Type>
		void RemoveEntry(Handle<Type>& _hHandle);
	};
};

#include "HandleManager.inl"