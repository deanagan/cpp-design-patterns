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

    namespace ElementType
    {
        using TextElementPtr = std::unique_ptr<TextElement>;
    }
}
