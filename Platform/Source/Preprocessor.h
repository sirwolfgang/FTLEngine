//===============================================================
// File:	Preprocessor.h
// Purpose: To handle platform specific #defines and macros
//===============================================================
#pragma once
#include "DLL.h"

#ifdef _DEBUG
#define PLATFORM_DEBUG
#else
#define PLATFORM_RELEASE
#endif

#ifdef _WIN64
#define PLATFORM_64_BIT
#define PLATFORM_WINDOWS
#elif _WIN32
#define PLATFORM_32_BIT
#define PLATFORM_WINDOWS
#endif

#ifdef _UNIX // TODO:: Add Unix Support
#define PLATFORM_UNIX
#endif

#ifdef PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#ifndef NULL
#define NULL 0
#endif