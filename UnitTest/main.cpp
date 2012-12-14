//===============================================================
// File:	UT Platform.cpp
// Purpose: To Unit Test the platform DLL
//===============================================================
#include <gtest/gtest.h>

#include "Tests\Platform\Platform.h"

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}