#pragma once
#include "ISubject.h"
#include "IObserver.h"

#include <gmock/gmock.h>

#include <string>

namespace ObserverPatternTest
{

template<typename ObservableType>
class MockObserver : public ObserverPattern::IObserver<ObservableType>
{
 public:
    MOCK_METHOD(void, Update, (ObservableType& ot), (override));
    MOCK_METHOD(int, TotalItems, (), (const, override));
};

}
