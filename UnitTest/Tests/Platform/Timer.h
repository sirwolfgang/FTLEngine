//===============================================================
// File:	Timer.h
// Purpose: Platform/Timer Unit Tests
//===============================================================
#include <Platform.h>

TEST(Platform_Timer, Is_Not_NULL)
{
	EXPECT_NE(NULL, Platform::GetCurrentTime_Milliseconds());
}

TEST(Platform_Timer, Is_Time_Based)
{
	float64 Tick1 = Platform::GetCurrentTime_Milliseconds();
	Sleep(10);
	float64 Tick2 = Platform::GetCurrentTime_Milliseconds();

	EXPECT_TRUE(Tick1 < Tick2);
}