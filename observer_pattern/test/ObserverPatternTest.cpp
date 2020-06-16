#include "Customer.h"
#include "Retailer.h"
#include "MockObserver.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace ObserverPatternTest
{
    namespace
    {

    }


    template <typename T>
    class ObserverPatternTestShould : public ::testing::Test
    {
    protected:

        void SetUp() override
        {

        }

        void TearDown() override
        {

        }
    };

    struct Coordinate
    {
        int x;
        int y;

        bool operator==(const Coordinate& coordinate) const {
            return (coordinate.x == x) && (coordinate.y == y);
        }

        bool operator !=(const Coordinate& coordinate) const {
            return !(coordinate == *this);
        }
    };

    using TypesToTest = ::testing::Types<int, std::string, float, Coordinate>;
    TYPED_TEST_SUITE(ObserverPatternTestShould, TypesToTest);

    TYPED_TEST(ObserverPatternTestShould, CheckCustomer_UpdatesTotalItem_WhenUpdateInvoked)
    {
        using namespace std;

        // Arrange
        TypeParam param;
        auto customer = make_unique<ObserverPattern::Customer<TypeParam>>();

        // Act
        customer->Update(param);

        // Assert
        EXPECT_EQ(1, customer->TotalItems());
    }

    TYPED_TEST(ObserverPatternTestShould, CheckMockObserver_ReceivesNotification_WhenActualRetailerNotifies)
    {
        using namespace std;

        // Arrange
        TypeParam param;
        auto mockObserver = make_unique<MockObserver<TypeParam>>();
        auto retailer = make_unique<ObserverPattern::Retailer<TypeParam>>();
        auto updateCount = 0;

        EXPECT_CALL(*mockObserver.get(), Update(param)).WillOnce(testing::Invoke(
            [&updateCount] (auto param) {
                ++updateCount;
            }
        ));

        retailer->Register(*mockObserver.get());

        // Act
        retailer->Notify(param);

        // Assert
        EXPECT_EQ(1, updateCount);

    }


}
