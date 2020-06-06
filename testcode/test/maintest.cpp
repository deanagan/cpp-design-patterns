#include "main.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace MainTest
{
class MainTestShould : public ::testing::Test
{
protected:
    void SetUp() override {
    }

    void TearDown() override {

    }

    TestCode::MathOp mathOp_;
};

class MainParameteredTestShould : public MainTestShould,
                           public ::testing::WithParamInterface<std::tuple<int, int, int>> {

};

INSTANTIATE_TEST_SUITE_P(AddendsThenExpectedSum,
                         MainParameteredTestShould,
                         testing::Values(
                             std::make_tuple(1,2,3),
                             std::make_tuple(7,3,10),
                             std::make_tuple(15,2,17),
                             std::make_tuple(18,2,20),
                             std::make_tuple(21,2,23)
                         ));

TEST_P(MainParameteredTestShould, SumIsCorrect_WhenUsingParameteredTest) {
    // Arrange
    int x,y,total;
    std::tie (x,y,total) = GetParam();

    // Act
    const auto result = mathOp_.Sum(x,y);

    // Assert
    EXPECT_EQ(total, result);
}

TEST_F(MainTestShould, SumIsCorrect_WhenGiven2PositiveNumbers)
{
    // Arrange
    TestCode::MathOp mathOp;

    // Act
    const auto result = mathOp.Sum(1,3);

    // Assert
    EXPECT_EQ(4, result);
}

}
