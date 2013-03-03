//===============================================================
// File:	Timer.cpp
// Purpose: To handle platform depend High Resolution Timer functionality
//===============================================================
#include "Timer.h"

float64 Platform::GetCurrentTime_Milliseconds(void)
{
#ifdef PLATFORM_WINDOWS
	LARGE_INTEGER TicksPerSecond;
	LARGE_INTEGER Tick;

	QueryPerformanceFrequency(&TicksPerSecond);
	assert(GetLastError() == 0);

	QueryPerformanceCounter(&Tick);
	assert(GetLastError() == 0);

	return Tick.QuadPart * 1000.0 / TicksPerSecond.QuadPart;
#endif

#ifdef PLATFORM_UNIX
	// TODO:: Add Unix Support
#endif

	return NULL;
}