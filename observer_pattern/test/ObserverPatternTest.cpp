#include "Customer.h"
#include "MockSubject.h"
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

    using TypesToTest = ::testing::Types<int, std::string>;
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

    TYPED_TEST(ObserverPatternTestShould, DISABLED_CheckMockObserver_ReceivesNotification_WhenActualRetailerNotifies)
    {
        using namespace std;

        // Arrange
        //auto mockObserver = make_unique<MockObserver>();
        //auto retailer = make_unique<Retailer<TypeParam>();
        // auto updateCount = 0;

        // ON_CALL(*mockObserver.get(), Update(testing::_)).WillByDefault(testing::Invoke(
        //     [&updateCount] {
        //         ++updateCount;
        //     }
        // ));
        // retailer.Register(mockObserver);

        // // Act
        // retailer.Notify(someObject);

        // // Assert
        // EXPECT_EQ(1, updateCount);

    }


}