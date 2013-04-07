//===============================================================
// File:	Camera.cpp
// Purpose: To handle camera functionality within context of 
//			 view management
//===============================================================
#include "Camera.h"

//---------------------------------------------------------------
Camera::Camera()
{
	m_viewMatrix		= XMMatrixIdentity();
	m_perspectiveMatrix = XMMatrixIdentity();
}

//---------------------------------------------------------------
Camera::Camera(Camera const& _That)
{
	m_viewMatrix		= _That.m_viewMatrix;
	m_perspectiveMatrix = _That.m_perspectiveMatrix;
}

//---------------------------------------------------------------
Camera::~Camera()
{

}

//---------------------------------------------------------------
Camera& Camera::operator=(Camera const& _That)
{
	m_viewMatrix		= _That.m_viewMatrix;
	m_perspectiveMatrix = _That.m_perspectiveMatrix;

	return *this;
}