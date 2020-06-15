#pragma once
#include "ISubject.h"
#include "IObserver.h"

#include <gmock/gmock.h>

#include <string>

namespace ObserverPatternTest
{

template<typename ObservableType>
class MockSubject : public ObserverPattern::ISubject<ObservableType>
{
 public:
    MOCK_METHOD(void, Register, (ObserverPattern::IObserver<ObservableType>& observer), (override));
    MOCK_METHOD(void, Notify, (ObservableType& ot), (const, override));

};

}
