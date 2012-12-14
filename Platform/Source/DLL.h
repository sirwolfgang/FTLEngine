//===============================================================
// File:	DLL.h
// Purpose: To Handle DLL Wraping
//===============================================================
#pragma once

#ifdef PLATFORM_EXPORTS
#define PLATFORM_API __declspec(dllexport)
#else
#define PLATFORM_API __declspec(dllimport)
#endif