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