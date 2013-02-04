//===============================================================
// File:	Handle.inl
// Purpose: To handle the handles that handle pointers.
//===============================================================
template <typename Type>
inline Platform::Handle<Type>::Handle()
{
	m_pManager	= nullptr;
	m_nIndex	= NULL;
	m_nUsageID	= NULL;
}

//---------------------------------------------------------------
template <typename Type>
inline Platform::Handle<Type>::Handle(Handle const& _That)
{
	m_pManager	= _That.m_pManager; 
	m_nIndex	= _That.m_nIndex;
	m_nUsageID	= _That.m_nUsageID;

	if(m_pManager)
		m_pManager->AddReference(m_nIndex, m_nUsageID);
}

//---------------------------------------------------------------
template <typename Type>
inline Platform::Handle<Type>::~Handle()
{
	if(m_pManager)
		m_pManager->ReleaseReference(m_nIndex, m_nUsageID);
}

//---------------------------------------------------------------
template <typename Type>
inline Type* Platform::Handle<Type>::RetrieveEntry()
{
	if(m_pManager)
		return (Type*)m_pManager->RetrieveEntry(m_nIndex, m_nUsageID);
	return nullptr;
}

//---------------------------------------------------------------
template <typename Type>
inline uint32 Platform::Handle<Type>::GetReferenceCount()
{
	if(m_pManager)
		return m_pManager->GetReferenceCount(m_nIndex, m_nUsageID);
	return NULL;
}

//---------------------------------------------------------------
template <typename Type>
inline Platform::Handle<Type>& Platform::Handle<Type>::operator=(Handle const& _That)
{
	if(m_pManager)
		m_pManager->ReleaseReference(m_nIndex, m_nUsageID);

	m_pManager	= _That.m_pManager; 
	m_nIndex	= _That.m_nIndex;
	m_nUsageID	= _That.m_nUsageID;

	if(m_pManager)
		m_pManager->AddReference(m_nIndex, m_nUsageID);

	return *this;
}

//---------------------------------------------------------------
template <typename Type>
inline Type Platform::Handle<Type>::operator->()
{
	return *RetrieveEntry();
}

//---------------------------------------------------------------
template <typename Type>
inline Type Platform::Handle<Type>::operator*()
{
	return *RetrieveEntry();
}
