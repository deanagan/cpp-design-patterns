#pragma once
#include "IObserver.h"
#include <vector>

namespace ObserverPattern
{
template<typename ObservableType>
class Customer : public IObserver<ObservableType>
{
public:
    void Update(ObservableType& ot) override;

private:
    std::vector<ObservableType> cartItems_;
};

}
