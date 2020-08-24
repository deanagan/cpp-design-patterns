#pragma once

#include "CountView.h"
#include <map>

namespace CuriouslyRecurringTemplatePattern
{
    class AnyCharCounter : public CountView<AnyCharCounter>
    {
    public:
        AnyCharCounter() = default;
        void Count(const std::string &input) override;
        void Clear(const ClearCompletionFunctionType &fn) override;


    private:
        std::map<char, int> countResults_;

        // We want to hide the result method from the public world but give
        // access to the countview class
        std::vector<CountedType> Result() const override;
        friend class CountView<AnyCharCounter>;
    };
} // namespace CuriouslyRecurringTemplatePattern
