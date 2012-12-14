//===============================================================
// File:	UT Platform.cpp
// Purpose: To Unit Test the platform DLL
//===============================================================
#include <gtest/gtest.h>

TEST(Platform, High_Res_Timer)
{
	EXPECT_NE(NULL, 5);
	ASSERT_NE(NULL, 3);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}