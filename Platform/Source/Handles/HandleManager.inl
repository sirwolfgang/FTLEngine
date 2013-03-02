//===============================================================
// File:	HandleManager.inl
// Purpose: To act as a general purpose manager of handles
//===============================================================
template<typename Type>
inline Platform::Handle<Type> Platform::HandleManager::CreateHandle(Type* _pEntry)
{
	Handle<Type>	hHandle;
	memsize_s		nIndex;

	if(m_FreeList.size() > 0)
	{
		nIndex = m_FreeList.back();
		m_FreeList.pop_back();

		m_Handles[nIndex].m_nReferenceCount	= 1;
		m_Handles[nIndex].m_pEntry			= _pEntry;	
	}
	else
	{
		HandleEntry Entry;
		Entry.m_nReferenceCount = 1;
		Entry.m_nUsageID		= 0;
		Entry.m_pEntry			= _pEntry;

		m_Handles.push_back(Entry);
		nIndex = m_Handles.size() - 1;
	}

	hHandle.m_nIndex	= nIndex;
	hHandle.m_nUsageID	= m_Handles[nIndex].m_nUsageID;
	hHandle.m_pManager	= this;

	return hHandle;
}

//---------------------------------------------------------------
template<typename Type>
inline void Platform::HandleManager::RemoveEntry(Handle<Type>& _hHandle)
{
	ReleaseReference(_hHandle.m_nIndex, _hHandle.m_nUsageID);

	m_Handles[_hHandle.m_nIndex].m_nUsageID++;
	m_Handles[_hHandle.m_nIndex].m_pEntry = nullptr;

	m_FreeList.push_back(_hHandle.m_nIndex);

	_hHandle = Handle<Type>();
}