//===============================================================
// File:	Timer.h
// Purpose: To handle platform depend High Resolution Timer functionality
//===============================================================
#pragma once
#include "Preprocessor.h"
#include "DataTypes.h"

namespace Platform
{
	float64 GetCurrentTime_Milliseconds(void);
}