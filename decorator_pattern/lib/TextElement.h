#pragma once

#include "ITextElement.h"
#include <string>

namespace DecoratorPattern
{
    class TextElement : public ITextElement
    {
        public:
        explicit TextElement(std::string id);
        std::string Value() const override;

    };
}
