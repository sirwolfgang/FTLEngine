//===============================================================
// File:	DLL.h
// Purpose: To Handle DLL Wraping
//===============================================================
#pragma once

#ifdef CORE_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif