//===============================================================
// File:	Camera.h
// Purpose: To handle camera functionality within context of 
//			 view management
//===============================================================
#pragma once
#include <FTLPlatform.h>

namespace Core
{
	namespace Graphics
	{
		class Camera
		{
			XMMATRIX m_viewMatrix;
			XMMATRIX m_perspectiveMatrix;

		public:
			enum EMode
			{
				EMODE_PERSPECTIVE,
				EMODE_ORTHOGONAL,
			};

			struct Settings
			{
				EMode eMode;
				float fWidth;
				float fHeight;
				float fNear;
				float fFar;
				float fFOV;
			};

		private:
			Camera();

		public:
			Camera(Settings _tSettings);
			Camera(Camera const& _That);
			~Camera();

			Camera& operator=(Camera const& _That);

			XMMATRIX& GetViewMatrix();
			XMMATRIX& GetPerspectiveMatrix();
		};

	}
}

#include "Camera.inl"