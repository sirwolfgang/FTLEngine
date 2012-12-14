//===============================================================
// File:	Timer.h
// Purpose: Platform/Timer Unit Tests
//===============================================================
#include <Platform.h>

TEST(Platform_DataTypes, Is_Correct_Size)
{
	ASSERT_EQ(sizeof(uint8), 1);
	ASSERT_EQ(sizeof(uint16), 2);
	ASSERT_EQ(sizeof(uint32), 4);
	ASSERT_EQ(sizeof(uint64), 8);

	ASSERT_EQ(sizeof(int8), 1);
	ASSERT_EQ(sizeof(int16), 2);
	ASSERT_EQ(sizeof(int32), 4);
	ASSERT_EQ(sizeof(int64), 8);

	ASSERT_EQ(sizeof(float32), 4);
	ASSERT_EQ(sizeof(float64), 8);

#ifdef PLATFORM_32_BIT
	ASSERT_EQ(sizeof(memsize), 4);
#endif

#ifdef PLATFORM_64_BIT
	ASSERT_EQ(sizeof(memsize), 8);
#endif
}