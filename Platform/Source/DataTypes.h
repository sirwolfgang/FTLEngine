//===============================================================
// File:	DataTypes.h
// Purpose: To handle platform datatypes
//===============================================================
#pragma once
#include "Preprocessor.h"

typedef wchar_t				utf16;
typedef char				utf8;

typedef	unsigned char		uint8;
typedef	unsigned short		uint16;
typedef	unsigned long		uint32;
typedef	unsigned long long	uint64;
		
typedef	char				int8;
typedef	short				int16;
typedef	long				int32;
typedef	long long			int64;

typedef	float				float32;
typedef	double				float64;

// 32 bit to 64 bit Compatibility
//		memsize: can store sizes of pointers or indexes of the largest arrays per architecture
#ifdef PLATFORM_32_BIT
typedef uint32				memsize_u;
typedef int32				memsize_s;
#endif

#ifdef PLATFORM_64_BIT
typedef uint64				memsize_u;
typedef int64				memsize_s;
#endif