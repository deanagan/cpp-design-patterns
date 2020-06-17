#pragma once

#include "ISubject.h"
#include <algorithm>
#include <utility>
#include <functional>
#include <iostream>

namespace ObserverPattern
{

template<typename ObservableType>
class Retailer : public ISubject<ObservableType>
{
public:
    using ObserverType = IObserver<ObservableType>;
    void Register(ObserverType& observer) override
    {
        subscribers_.push_back(observer);
    }

    void Notify(ObservableType& ot) const override
    {
        std::for_each(begin(subscribers_), end(subscribers_), [&ot](const auto& sub) {
            sub.get().Update(ot);
        });
    }


private:
    std::vector<std::reference_wrapper<ObserverType>> subscribers_;
};
}
