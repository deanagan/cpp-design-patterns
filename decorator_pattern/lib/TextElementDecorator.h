#pragma once

#include "TextElement.h"
#include <string>

namespace DecoratorPattern
{
    class TextElementDecorator : public TextElement
    {
        protected:
        virtual TextElement* GetWrappedTextElement() const = 0;

    };
}
