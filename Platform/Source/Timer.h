//===============================================================
// File:	Timer.h
// Purpose: To handle platform depend High Resolution Timer functionality
//===============================================================
#pragma once
#include "Preprocessor.h"
#include "DataTypes.h"

namespace Platform
{
	PLATFORM_API float64 GetCurrentTick_Milliseconds(void);
}