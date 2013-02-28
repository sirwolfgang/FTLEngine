//===============================================================
// File:	Engine.h
// Purpose: To handle game engine runtime, and scope
//===============================================================
#pragma once
#include <FTLPlatform.h>
#include <FTLCore.h>

namespace Core
{
	class Engine_DLL : public Engine
	{

		Engine_DLL();
	public:
		struct InitializationData
		{
			HINSTANCE	m_hInstance;
			LPSTR		m_lpCmdLine;
			int32		m_nCmdShow;
		};

		Engine_DLL(InitializationData& _InitializationData);
		virtual ~Engine_DLL();
	};
}