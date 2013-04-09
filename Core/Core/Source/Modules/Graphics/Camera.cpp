//===============================================================
// File:	Camera.cpp
// Purpose: To handle camera functionality within context of 
//			 view management
//===============================================================
#include "Camera.h"
using namespace Core::Graphics;

//---------------------------------------------------------------
Camera::Camera()
{
	m_viewMatrix		= XMMatrixIdentity();
	m_perspectiveMatrix = XMMatrixIdentity();
}

//---------------------------------------------------------------
Camera::Camera(Settings _tSettings)
{
	m_viewMatrix = XMMatrixIdentity();

	switch(_tSettings.eMode)
	{
	case EMODE_PERSPECTIVE: m_perspectiveMatrix = XMMatrixPerspectiveFovLH( _tSettings.fFOV, _tSettings.fWidth / _tSettings.fHeight, _tSettings.fNear, _tSettings.fFar);
	case EMODE_ORTHOGONAL:	m_perspectiveMatrix = XMMatrixOrthographicLH(_tSettings.fWidth, _tSettings.fHeight, _tSettings.fNear, _tSettings.fFar);
	default:				m_perspectiveMatrix = XMMatrixIdentity(); 
		// TODO:: Throw Error
	}
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