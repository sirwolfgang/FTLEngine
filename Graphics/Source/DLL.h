//===============================================================
// File:	DLL.h
// Purpose: To Handle DLL Wraping
//===============================================================
#pragma once

#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else
#define GRAPHICS_API __declspec(dllimport)
#endif