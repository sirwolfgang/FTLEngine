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
			HINSTANCE	hInstance;
			LPSTR		lpCmdLine;
			int32		nCmdShow;
		};

		virtual ~Engine(){}

		virtual int32 Run() = 0;
	};
}