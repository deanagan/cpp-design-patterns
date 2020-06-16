#pragma once

#include "ISubject.h"
#include <algorithm>

namespace ObserverPattern
{

template<typename ObservableType>
class Retailer : public ISubject<ObservableType>
{
public:
    void Register(IObserver<ObservableType>& observer) override
    {
        subscribers_.push_back(&observer);
    }

    void Notify(ObservableType& ot) const override
    {
        std::for_each(begin(subscribers_), end(subscribers_), [&ot](const auto& sub) {
            sub->Update(ot);
        });
    }
private:
    std::vector<IObserver<ObservableType>*> subscribers_;
};

}
