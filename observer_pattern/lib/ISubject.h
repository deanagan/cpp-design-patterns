#pragma once

#include "IObserver.h"

namespace ObserverPattern
{

template<typename ObservableType>
class ISubject
{
public:
    virtual void Register(IObserver<ObservableType>& observer) = 0;
    virtual void Notify(ObservableType& ot) const = 0;

    virtual ~ISubject() = default;
};
}
