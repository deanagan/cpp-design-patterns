#pragma once

#include "ITextElement.h"
#include <string>

namespace DecoratorPattern
{
    class ITextElementDecorator : public ITextElement
    {
        protected:
        virtual ElementType::TextElementPtr GetWrappedTextElement() const = 0;

    };
}
