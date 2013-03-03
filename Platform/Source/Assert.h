//===============================================================
// File:	Assert.h
// Purpose: To handle platform independence with assertions 
//===============================================================
#pragma once
#include "Preprocessor.h"

#undef  assert

#ifndef  PLATFORM_DEBUG
	#define assert(_bCondition)\
		do\
		{\
			(void)sizeof(_bCondition);\
		}\
		while(0)
#else
	#define assert(_bCondition)\
		do\
		{\
			if(!(_bCondition))\
			{\
				abort();\
			}\
		}\
		while(0)
#endif