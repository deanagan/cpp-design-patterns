#pragma once

#include <string>
#include <memory>

namespace DecoratorPattern
{

    class TextElement
    {
        public:
        virtual std::string Value() const = 0;
        virtual ~TextElement() = default;
    };

}
