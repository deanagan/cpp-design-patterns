#pragma once

#include "Counter.h"
#include <algorithm>
#include <functional>

namespace CuriouslyRecurringTemplatePattern
{
    template <typename CounterType>
    class CountView : public Counter
    {
    public:
        void Count(const std::string &input) override
        {
            auto *counter = static_cast<CounterType *>(this);

            counter->Count(input);
        }

        void Show(const Counter::ReportFunctionType &fn) override
        {
            const auto *counter = static_cast<CounterType *>(this);
            const auto result = counter->Result();

            std::for_each(begin(result), end(result), [&fn](const decltype(result)::value_type &entry) {
                fn(entry);
            });
        }

        void Clear(const Counter::ClearCompletionFunctionType &fn) override
        {
            const auto counter = static_cast<CounterType *>(this);
            counter->Clear(fn);
        }

    protected:
        CountView() = default;
        CountView(const CountView &) = default;
        CountView(CountView &&) = default;
    };

} // namespace CuriouslyRecurringTemplatePattern
