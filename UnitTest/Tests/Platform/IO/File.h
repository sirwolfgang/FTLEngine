//===============================================================
// File:	File.h
// Purpose: Platform/IO/Files Unit Tests
//===============================================================
#pragma once
#include <cstring>

TEST(Platform_IO_Files, Can_Read_Write)
{
	Platform::File UnitTestFile("UnitTest.txt", Platform::File::EOPEN_TRUNCATE, Platform::File::EDATA_ASCII, Platform::File::EPERMISSION_READ_WRITE);

	char Output[]				= "Testing Output";
	char Input[sizeof(Output)]	= {};

	// Is File Open, Ready to Use
	EXPECT_EQ(0, UnitTestFile.GetHeadPosition());

	// Test Write
	UnitTestFile.Write(sizeof(Output), Output);

	// Did Write to file Move Head
	EXPECT_EQ(sizeof(Output), UnitTestFile.GetHeadPosition());

	// Move Head to begining
	UnitTestFile.MoveHead(Platform::File::EPOSITION_BEGIN);
	
	// Is Head at Begining
	EXPECT_EQ(0, UnitTestFile.GetHeadPosition());

	// Read In File
	UnitTestFile.Read(sizeof(Input), Input);

	// Did head move with read
	EXPECT_EQ(sizeof(Input), UnitTestFile.GetHeadPosition());

	// Did String Read/Write Correctly?
	EXPECT_EQ(0, strcmp(Output, Input));
}