#include "HtmlValue.h"
#include "BoldenText.h"
#include "TextElement.h"
#include "MockHtmlValue.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace DecoratorPatternTest
{
    namespace
    {
        static const std::string TITLE = "Harry Potter and the Prisoner of Azkaban";
        static const std::string BOLD_TITLE = "<b>Harry Potter and the Prisoner of Azkaban</b>";
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
        auto title = std::make_unique<DecoratorPattern::HtmlValue>(TITLE);

        EXPECT_EQ(TITLE, title->Value());
    }

    TEST_F(DecoratorPatternTestShould, ExpectValueInstanceHtmlified_WhenUsingTitleValueDecorator)
    {
        auto mockTitle = std::make_unique<::testing::NiceMock<MockHtmlValue>>();

        ON_CALL(*mockTitle.get(), Value()).WillByDefault(testing::Invoke(
            [] {
                return TITLE;
            }
        ));

        auto htmlifiedTitle = std::make_unique<DecoratorPattern::BoldenText>(mockTitle.get());

        EXPECT_EQ(BOLD_TITLE, htmlifiedTitle->Value());
    }


}
