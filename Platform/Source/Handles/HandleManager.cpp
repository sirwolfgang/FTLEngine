//===============================================================
// File:	HandleManager.cpp
// Purpose: To act as a general purpose manager of handles
//===============================================================
#include "HandleManager.h"
using namespace Platform;

//---------------------------------------------------------------
HandleManager::HandleManager()
{

}

//---------------------------------------------------------------
HandleManager::HandleManager(HandleManager const& _That)
{

}

//---------------------------------------------------------------
HandleManager::~HandleManager()
{

}

//---------------------------------------------------------------
HandleManager& HandleManager::operator=(HandleManager const& _That)
{
	return *this;
}

//---------------------------------------------------------------
void* HandleManager::RetrieveEntry(memsize _nIndex, uint32 _nUsageID)
{
	if(m_Handles[_nIndex].m_nUsageID == _nUsageID)
	{
		return m_Handles[_nIndex].m_pEntry;
	}
	return nullptr;
}

//---------------------------------------------------------------
void HandleManager::AddReference(memsize _nIndex, uint32 _nUsageID)
{
	if(m_Handles[_nIndex].m_nUsageID == _nUsageID)
	{
		m_Handles[_nIndex].m_nReferenceCount++;
	}
}

//---------------------------------------------------------------
uint32 HandleManager::GetReferenceCount(memsize _nIndex, uint32 _nUsageID)
{
	if(m_Handles[_nIndex].m_nUsageID == _nUsageID)
	{
		return m_Handles[_nIndex].m_nReferenceCount;
	}
	return NULL;
}

//---------------------------------------------------------------
void HandleManager::ReleaseReference(memsize _nIndex, uint32 _nUsageID)
{
	if(m_Handles[_nIndex].m_nUsageID == _nUsageID)
	{
		// TODO:: Assert on ReferenceCount is 0
		m_Handles[_nIndex].m_nReferenceCount--;
	}
}