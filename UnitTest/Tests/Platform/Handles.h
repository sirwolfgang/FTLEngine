//===============================================================
// File:	Handles.h
// Purpose: Platform/Handles Unit Tests
//===============================================================
TEST(Platform_Handles, Can_Store_Data)
{
	Platform::HandleManager Manager;

	uint32 Data = 7;
	Platform::Handle<uint32> hData(Manager.CreateHandle(&Data));

	EXPECT_EQ(Data, *hData);
}

//---------------------------------------------------------------
TEST(Platform_Handles, Modifiable_Values)
{
	Platform::HandleManager Manager;

	uint32 Data = 0;
	Platform::Handle<uint32> hData(Manager.CreateHandle(&Data));

	uint32 i = 0;
	for(Data = 0; Data < 10; (*hData)++)
	{
		EXPECT_EQ(Data, *hData);
		EXPECT_EQ(i++, *hData);
	}
}

//---------------------------------------------------------------
TEST(Platform_Handles, Correct_Reference_Counting)
{
	Platform::HandleManager Manager;
	Platform::Handle<uint32> hData[2];

	uint32 Data = 5;
	
	// Creation
	hData[0] = Manager.CreateHandle(&Data);
	EXPECT_EQ(1, hData->GetReferenceCount());

	// Assigment Into
	hData[1] = hData[0];
	EXPECT_EQ(2, hData->GetReferenceCount());

	// Assigment Over
	hData[1] = Platform::Handle<uint32>();
	EXPECT_EQ(1, hData->GetReferenceCount());

	{
		// Copy Constructor
		Platform::Handle<uint32> tmpHandle(hData[0]);
		EXPECT_EQ(2, hData->GetReferenceCount());
	}
	// Destruction
	EXPECT_EQ(1, hData->GetReferenceCount());

	// Removing Entry
	Manager.RemoveEntry(hData[0]);
	EXPECT_EQ(0, hData->GetReferenceCount());
}

//---------------------------------------------------------------
TEST(Platform_Handles, Is_Boolable)
{
	Platform::HandleManager Manager;
	Platform::Handle<uint32> hData;

	// Empty Handle
	EXPECT_FALSE(hData);

	uint32 Data = 5;
	hData = Manager.CreateHandle(&Data);

	// Full Handle
	EXPECT_TRUE(hData);

	Manager.RemoveEntry(hData);

	// Removed Handle
	EXPECT_FALSE(hData);

	// Assigned Handle
	hData = Manager.CreateHandle(&Data);
	EXPECT_TRUE(hData);

	hData = Platform::Handle<uint32>();
	EXPECT_FALSE(hData);
}