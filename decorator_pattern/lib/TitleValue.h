#pragma once

#include "TextElement.h"
#include <string>

namespace DecoratorPattern
{
    class TitleValue : public TextElement
    {
        public:
        explicit TitleValue(std::string title);
        std::string Value() const override;

        private:
        std::string title;

    };
}
