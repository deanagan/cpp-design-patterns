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

    struct Coordinate final
    {
        int x { 0 };
        int y { 0 };

        bool operator==(const Coordinate& coordinate) const {
            return (coordinate.x == x) && (coordinate.y == y);
        }

        bool operator !=(const Coordinate& coordinate) const {
            return !(coordinate == *this);
        }
    };

    using TypesToTest = ::testing::Types<std::string, Coordinate, int, float>;
    TYPED_TEST_SUITE(ObserverPatternTestShould, TypesToTest);

    TYPED_TEST(ObserverPatternTestShould, Check_CustomerUpdatesTotalItem_WhenUpdateInvoked)
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

    TYPED_TEST(ObserverPatternTestShould, Check_MockObserverReceivesNotification_WhenActualRetailerNotifies)
    {
        using namespace std;

        // Arrange
        TypeParam param{};
        MockObserver<TypeParam> mockObserver;
        auto retailer = make_unique<ObserverPattern::Retailer<TypeParam>>();
        auto updateCount = 0;

        EXPECT_CALL(mockObserver, Update(param)).WillOnce(testing::Invoke(
           [&updateCount] (TypeParam /*p*/) {
               ++updateCount;
           }
        ));

        retailer->Register(mockObserver);

        // Act
        retailer->Notify(param);

        // Assert
        EXPECT_EQ(1, updateCount);
    }


}
