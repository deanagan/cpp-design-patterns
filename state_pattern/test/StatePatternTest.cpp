#include "Miles.h"
#include "EarningStatusContext.h"
#include "gtest/gtest.h"

class StatePatternTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
    }

    void TearDown() override 
    {

    }
    
    FrequentFlyers::Miles mMiles;
    FrequentFlyers::EarningStatusContext mEarningStatusContext;
};

TEST_F(StatePatternTest, ShouldExpect_MilesToIncreaseByAccruedMiles_WhenAccruingMilesinRedStatus) 
{
    // Arrange
    mMiles.Level = "Red";
    mMiles.TotalAccumulatedMiles = 10;

    // Act
    mMiles = mEarningStatusContext.UpdateMiles(mMiles, 30);

    // Assert
    EXPECT_EQ(40, mMiles.TotalAccumulatedMiles);
}


TEST_F(StatePatternTest, ShouldExpect_MilesToGoIntoGoldStatus_WhenAccruingMilesOverGoldStatusThreshold) 
{
    // Arrange
    mMiles.Level = "Red";
    mMiles.TotalAccumulatedMiles = 10;

    // Act
    mMiles = mEarningStatusContext.UpdateMiles(mMiles, 200);
    mMiles = mEarningStatusContext.UpdateMiles(mMiles, 100);

    // Assert
    EXPECT_EQ(315, mMiles.TotalAccumulatedMiles);
    EXPECT_EQ("Gold", mMiles.Level);
}