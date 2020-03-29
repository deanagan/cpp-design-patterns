#pragma once

#include "TextElement.h"
#include <string>

namespace DecoratorPattern
{
    class HtmlValue : public TextElement
    {
        public:
        explicit HtmlValue(std::string title);
        std::string Value() const override;

        private:
        std::string title;

    };
}
