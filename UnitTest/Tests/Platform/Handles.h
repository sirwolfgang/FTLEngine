//===============================================================
// File:	Handles.h
// Purpose: Platform/Handles Unit Tests
//===============================================================

TEST(Platform_Handles, Are_Working)
{
	Platform::HandleManager Manager;

	uint32 Data[5] = {0, 1, 2, 3, 4};
	Platform::Handle<uint32> hData[5];

	for(uint32 i = 0; i < 5; ++i)
		hData[i] = Manager.CreateHandle(&Data[i]);

	EXPECT_EQ(0, *hData[0]);
	EXPECT_EQ(1, *hData[1]);
	EXPECT_EQ(2, *hData[2]);
	EXPECT_EQ(3, *hData[3]);
	EXPECT_EQ(4, *hData[4]);

	{
		Platform::Handle<uint32> hHandles[4];
		Platform::Handle<uint32> hHandle_1 = hData[1];
		Platform::Handle<uint32> hHandle_3 = hData[3];

		hHandles[0] = hHandle_1;
		hHandle_1	= hHandle_3;
		hHandles[1] = hHandles[0];
		hHandles[2] = hHandles[2];
		hHandles[2] = hHandle_3;
		hHandle_3	= hHandles[3];
	}

	(*hData[0]) = 7;
	(*hData[1]) = 8;
	(*hData[2]) = 9;

	EXPECT_EQ(7, *hData[0]);
	EXPECT_EQ(8, *hData[1]);
	EXPECT_EQ(9, *hData[2]);

	hData[3] = hData[2];
	hData[4] = hData[1];

	EXPECT_EQ(9, *hData[3]);
	EXPECT_EQ(8, *hData[4]);

	EXPECT_EQ(7, Data[0]);
	EXPECT_EQ(8, Data[1]);
	EXPECT_EQ(9, Data[2]);
	EXPECT_EQ(3, Data[3]);
	EXPECT_EQ(4, Data[4]);

	for(uint32 i = 0; i < 5; ++i)
		Manager.RemoveEntry(hData[i]);
}