#pragma once

#include "TitleValueDecorator.h"

namespace DecoratorPattern
{
    class HtmlifyText : public TitleValueDecorator
    {
        public:
        explicit HtmlifyText(ElementType::TextElementPtr& textElement);
        std::string Value() const override;
    };


}
