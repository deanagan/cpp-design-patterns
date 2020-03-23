#include "Miles.h"
#include "EarningStatusContext.h"
#include "RedEarningStatus.h"
#include "GoldEarningStatus.h"

#include "MockEarningStatus.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace StatePatternTest
{
class StatePatternTestShould : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {

    }

    FrequentFlyers::Miles mMiles;
};

TEST_F(StatePatternTestShould, ExpectMilesToIncreaseByAccruedMiles_WhenAccruingMilesinRedStatus)
{
    // Arrange
    FrequentFlyers::RedEarningStatus redStatus;
    FrequentFlyers::EarningStatusContext earningContext{&redStatus};
    mMiles.TotalAccumulatedMiles = 10;

    // Act
    mMiles = earningContext.UpdateMiles(mMiles, 100);

    // Assert
    EXPECT_EQ(110, mMiles.TotalAccumulatedMiles);
}


TEST_F(StatePatternTestShould, ExpectMilesToIncreaseByAccruedMilesWithBonus_WhenAccruingMilesinGoldStatus)
{
    // Arrange
    FrequentFlyers::GoldEarningStatus goldStatus;
    FrequentFlyers::EarningStatusContext earningContext{&goldStatus};
    mMiles.TotalAccumulatedMiles = 10;

    // Act
    mMiles = earningContext.UpdateMiles(mMiles, 100);

    // Assert
    EXPECT_EQ(115, mMiles.TotalAccumulatedMiles);
}

TEST_F(StatePatternTestShould, ExpectMilesToHaveNoBonus_WhenCreatingContextWithNullptr)
{
    // Arrange
    FrequentFlyers::EarningStatusContext earningContext{nullptr};
    mMiles.TotalAccumulatedMiles = 10;

    // Act
    mMiles = earningContext.UpdateMiles(mMiles, 100);

    // Assert
    EXPECT_EQ(10, mMiles.TotalAccumulatedMiles);
}

TEST_F(StatePatternTestShould, ExpectMilesToIncreaseByExpected_WhenAccruingMilesUsingMockedEarningStatus)
{
    // Arrange
    FrequentFlyers::Miles resultMiles;
    resultMiles.TotalAccumulatedMiles = 40;
    MockEarningStatus mockEarningStatus;
    FrequentFlyers::GoldEarningStatus goldStatus;
    FrequentFlyers::EarningStatusContext earningContext{&goldStatus};

    EXPECT_CALL(mockEarningStatus, UpdateMiles(testing::_, 30))
                .WillOnce(testing::Return(resultMiles));

    // Act
    earningContext.SetStatusLevel(&mockEarningStatus);
    mMiles = earningContext.UpdateMiles(mMiles, 30);

    // Assert
    EXPECT_EQ(40, mMiles.TotalAccumulatedMiles);
}
}
