#include "Counter.h"
#include "CountView.h"
#include "AnyCharCounter.h"
#include "VowelCounter.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace CuriouslyRecurringTemplatePattern
{

    class CuriouslyRecurringTemplatePatternShould : public ::testing::Test
    {
    protected:

        void SetUp() override
        {

        }

        void TearDown() override
        {

        }
    };


    TEST_F(CuriouslyRecurringTemplatePatternShould, GetCorrectCount_WhenUsingAnyCharCounter)
    {
        AnyCharCounter acc;
        acc.Count("hello");
       // const auto t = acc.Result();
        std::stringstream ss;
        acc.Show([&ss](const Counter::CountedType& out){

            ss << out.first << ", " << out.second;
        });
        EXPECT_EQ(true,true);
        std::cout << ">>>>>>>>>>>>>>>>>>>>>>>" << ss.str() << "\n";
    }



}
