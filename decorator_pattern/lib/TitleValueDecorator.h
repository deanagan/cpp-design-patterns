#pragma once

#include "TextElementDecorator.h"

namespace DecoratorPattern
{
    class TitleValueDecorator : public TextElementDecorator
    {
        public:
        explicit TitleValueDecorator(TextElement* textToWrap);
        TextElement* GetWrappedTextElement() const override final;

        private:
        TextElement* wrappedText;
    };
}
