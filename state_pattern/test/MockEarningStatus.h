#pragma once

#include "IEarningStatus.h"

#include <gmock/gmock.h>


namespace StatePatternTest
{
class MockEarningStatus : public FrequentFlyers::IEarningStatus
{
 public:
  MOCK_METHOD(FrequentFlyers::Miles, UpdateMiles, (const FrequentFlyers::Miles& miles, int earnedMiles), (override));

};
}
