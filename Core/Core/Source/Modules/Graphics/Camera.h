//===============================================================
// File:	Camera.h
// Purpose: To handle camera functionality within context of 
//			 view management
//===============================================================
#pragma once
#include <FTLPlatform.h>

class Camera
{
	XMMATRIX m_viewMatrix;
	XMMATRIX m_perspectiveMatrix;

public:
	Camera();
	Camera(Camera const& _That);
	~Camera();

	Camera& operator=(Camera const& _That);
};
