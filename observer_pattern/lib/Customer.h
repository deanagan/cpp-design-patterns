#pragma once
#include "IObserver.h"
#include <vector>

namespace ObserverPattern
{
template<typename ObservableType>
class Customer : public IObserver<ObservableType>
{
public:
    void Update(ObservableType& ot) override
    {
        cartItems_.push_back(ot);
    }

    int TotalItems() const override
    {
        return cartItems_.size();
    }

private:
    std::vector<ObservableType> cartItems_;
};

}
