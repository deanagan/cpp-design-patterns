#pragma once

#include "TitleValueDecorator.h"

namespace DecoratorPattern
{
    class BoldenText : public TitleValueDecorator
    {
        public:
        explicit BoldenText(TextElement* textElement);
        std::string Value() const override;
    };


}
