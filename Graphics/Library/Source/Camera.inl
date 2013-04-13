//===============================================================
// File:	Camera.inl
// Purpose: To handle camera functionality within context of 
//			 view management
//===============================================================
inline XMMATRIX& Core::Graphics::Camera::GetViewMatrix()
{
	return m_viewMatrix;
}

//---------------------------------------------------------------
inline XMMATRIX& Core::Graphics::Camera::GetPerspectiveMatrix()
{
	return m_perspectiveMatrix;
}