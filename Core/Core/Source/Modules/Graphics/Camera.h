//===============================================================
// File:	Camera.h
// Purpose: To handle camera functionality within context of 
//			 view management
//===============================================================
#pragma once
class Camera
{
public:
	Camera();
	Camera(Camera const& _That);
	~Camera();

	Camera& operator=(Camera const& _That);
};
