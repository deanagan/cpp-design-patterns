#pragma once

#include "ISubject.h"

namespace ObserverPattern
{

template<typename ObserverType>
class Retailer : public ISubject<ObserverType>
{
public:
    void Attach(IObserver observer) override
    {
        subscribers_.push_back(observer);
    }

    void Notify(ObservableType& ot) const override
    {
        std::for_each(begin(subscribers), end(subsribers), [](const auto& sub) {
            sub.Update(ot);
        });
    }
private:
    std::vector<ObserverType> subscribers_;
};

}
