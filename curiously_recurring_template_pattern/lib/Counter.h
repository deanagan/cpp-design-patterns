#pragma once

#include <string>
#include <vector>
#include <functional>

namespace CuriouslyRecurringTemplatePattern
{

    class Counter
    {
    public:
        Counter() = default;
        Counter(const Counter &) = default;
        Counter(Counter &&) = default;
        Counter &operator=(const Counter &) = default;
        Counter &operator=(Counter &&) = default;
        virtual ~Counter() = default;

        using CountedType = std::pair<char, int>;
        using ReportFunctionType = std::function<void(const Counter::CountedType &)>;
        using ClearCompletionFunctionType = std::function<void()>;

        virtual void Count(const std::string &input) = 0;
        virtual void Show(const ReportFunctionType &fn) = 0;
        virtual void Clear(const ClearCompletionFunctionType &fn) = 0;
        virtual std::vector<CountedType> Result() const = 0;
    };

} // namespace CuriouslyRecurringTemplatePattern
