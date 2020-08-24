#include "AnyCharCounter.h"
#include <algorithm>
#include <iterator>
#include <vector>

namespace CuriouslyRecurringTemplatePattern
{

    void AnyCharCounter::Count(const std::string &input)
    {
        for (const auto& ch: input)
        {
            if (countResults_.find(ch) == end(countResults_))
            {
                countResults_[ch] = 1;
            }
            else
            {
                countResults_[ch]++;
            }
        }
    }

    void AnyCharCounter::Clear(const ClearCompletionFunctionType &fn)
    {
        countResults_.clear();
        fn();
    }

    std::vector<Counter::CountedType> AnyCharCounter::Result() const
    {
        std::vector<Counter::CountedType> result;
        transform(begin(countResults_), end(countResults_), back_inserter(result),
            [](const decltype(countResults_)::value_type& val)
            {
                return CountedType(val);
            });

        return result;
    }

} // namespace CuriouslyRecurringTemplatePattern
