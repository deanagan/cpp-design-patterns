#pragma once

namespace ObserverPattern
{
template<typename ObservableType>
class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void Update(ObservableType& ot) = 0;
    virtual int TotalItems() const = 0;
};
}
