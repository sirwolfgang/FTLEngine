//===============================================================
// File:	Engine.h
// Purpose: To handle game engine runtime, and scope
//===============================================================
#pragma once
#include <FTLPlatform.h>

namespace Core
{
	class Engine
	{
	public:
		struct InitializationData
		{
			HINSTANCE	m_hInstance;
			LPSTR		m_lpCmdLine;
			int32		m_nCmdShow;
		};

		virtual ~Engine(){}
	};
}