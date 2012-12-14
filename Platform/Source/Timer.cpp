//===============================================================
// File:	Timer.cpp
// Purpose: To handle platform depend High Resolution Timer functionality
//===============================================================
#include "Timer.h"

PLATFORM_API float64 Platform::GetCurrentTick_Milliseconds(void)
{
#ifdef PLATFORM_WINDOWS
	LARGE_INTEGER TicksPerSecond;
	LARGE_INTEGER Tick;

	QueryPerformanceFrequency(&TicksPerSecond);
	QueryPerformanceCounter(&Tick);

	return Tick.QuadPart * 1000.0 / TicksPerSecond.QuadPart;
#endif

#ifdef PLATFORM_UNIX
	// TODO:: Add Unix Support
#endif

	return NULL;
}