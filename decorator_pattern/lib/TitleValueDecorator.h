#pragma once

#include "TextElementDecorator.h"

namespace DecoratorPattern
{
    class TitleValueDecorator : public TextElementDecorator
    {
        public:
        explicit TitleValueDecorator(ElementType::TextElementPtr& textToWrap);
        TextElement* GetWrappedTextElement() const override final;

        private:
        ElementType::TextElementPtr wrappedText;
    };
}
