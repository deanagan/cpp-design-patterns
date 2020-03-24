#pragma once

#include <string>
#include <memory>

namespace DecoratorPattern
{

    class ITextElement
    {
        public:
        virtual std::string Value() const = 0;
        virtual ~ITextElement() = default;
    };

    namespace ElementType
    {
        using TextElementPtr = std::unique_ptr<ITextElement>;
    }
}
