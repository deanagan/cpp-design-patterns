#pragma once
#include "Account.h"

#include <gmock/gmock.h>

#include <string>

namespace BuilderPatternTest
{
class MockAccount : public Accounts::Account
{
 public:
    MOCK_METHOD(void, Name, (std::string name), (override));
    MOCK_METHOD(void, InitialAmount, (int amount), (override));
    MOCK_METHOD(std::string, Name, (), (const, override));
    MOCK_METHOD(int, CurrentAmount, (), (const, override));
      
};

}
