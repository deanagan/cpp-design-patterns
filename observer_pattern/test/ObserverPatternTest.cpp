
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace ObserverPatternTest
{
    namespace
    {
        static const std::string TITLE = "Harry Potter and the Prisoner of Azkaban";
        static const std::string BOLD_TITLE = "<b>Harry Potter and the Prisoner of Azkaban</b>";
    }

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


    TEST_F(ObserverPatternTestShould, CheckCustomer_ReceivesNotification_WhenMockSubjectNotifies)
    {
        using namespace std;

        // Arrange
        auto mockSubject = make_unique<MockSubject>();
        auto customer = make_unique<Customer>();

        EXPECT_CALL(customer, Update(someobject)).Times(Once);
        mockSubject.Register(customer);

        // Act
        mockSubject.Notify(someObject);

        // Assert
        EXPECT_EQ(1, customer.TotalItems());
    }

    TEST_F(ObserverPatternTestShould, CheckMockObserver_ReceivesNotification_WhenActualRetailerNotifies)
    {
        using namespace std;

        // Arrange
        auto mockObserver = make_unique<MockObserver>();
        auto retailer = make_unique<Retailer>();
        auto updateCount = 0;

        ON_CALL(*mockObserver.get(), Update(testing::_)).WillByDefault(testing::Invoke(
            [&updateCount] {
                ++updateCount;
            }
        ));
        retailer.Register(mockObserver);

        // Act
        retailer.Notify(someObject);

        // Assert
        EXPECT_EQ(1, updateCount);

    }


}
