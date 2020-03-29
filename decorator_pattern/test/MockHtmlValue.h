#pragma once
#include "TextElementDecorator.h"

#include <gmock/gmock.h>

#include <string>

namespace DecoratorPatternTest
{
class MockHtmlValue : public DecoratorPattern::TextElement
{
 public:
    MOCK_METHOD(std::string, Value, (), (const, override));
};

}
