#include "TitleValue.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace DecoratorPatternTest
{
    namespace
    {
        static const std::string TITLE = "Harry Potter and the Prisoner of Azkaban";
    }

    class DecoratorPatternTestShould : public ::testing::Test
    {
    protected:


        void SetUp() override
        {

        }

        void TearDown() override
        {

        }
    };


    TEST_F(DecoratorPatternTestShould, ExpectValueInstanceMatch_WhenCreatingCoreTitleInstance)
    {
        auto title = std::make_unique<DecoratorPattern::TitleValue>(TITLE);

        EXPECT_EQ(TITLE, title->Value());
    }


}
