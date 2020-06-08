#include "main.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>

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
    std::cout << "Adding " << x << " and " << y << "\n";
    const auto result = mathOp_.Sum(x,y);

    // Assert
    EXPECT_EQ(total, result);
}


class NearestNumberFunctionShould : public MainTestShould,
                           public ::testing::WithParamInterface<std::tuple<std::vector<int>, int, int>> {

};

INSTANTIATE_TEST_SUITE_P(NumbersAndSearchPointThenExpectedClosest,
                         NearestNumberFunctionShould,
                         testing::Values(
                            std::make_tuple(std::vector<int>{4, 7, 10, 11, 12, 17}, 9, 10),
                            std::make_tuple(std::vector<int>{4, 7, 10, 11, 12, 17}, 8, 7),
                            std::make_tuple(std::vector<int>{4, 8, 10, 11, 12, 17}, 9, 8),
                            std::make_tuple(std::vector<int>{4, 9, 10, 11, 12, 17}, 9, 9),
                            std::make_tuple(std::vector<int>{4, 7, 10, 11, 12, 17}, 0, 4),
                            std::make_tuple(std::vector<int>{4, 7, 10, 11, 12, 17}, 100, 17),
                            std::make_tuple(std::vector<int>{5, 10, 8, 12, 89, 100}, 7, 8),
                            std::make_tuple(std::vector<int>{-1, 2, 3}, 0, -1),
                            std::make_tuple(std::vector<int>{0, -2}, -1, -2)
                         ));

TEST_P(NearestNumberFunctionShould, ReturnNearestNumber_WhenGivenParameters)
{
    // Arrange
    std::vector<int> numbers;
    int searchNumber, expectedResult;
    std::tie(numbers, searchNumber, expectedResult) = GetParam();
    // Act
    const auto result = mathOp_.NearestValue(numbers, searchNumber);
    // Assert
    EXPECT_EQ(result, expectedResult);
}

TEST_F(MainTestShould, DISABLED_SumIsCorrect_WhenGiven2PositiveNumbers)
{
    // Arrange
    TestCode::MathOp mathOp;

    // Act
    const auto result = mathOp.Sum(1,3);

    // Assert
    EXPECT_EQ(4, result);
}

}
