#pragma once
#include "Miles.h"
#include "EarningStatusDefinition.h"


namespace FrequentFlyers
{
class IEarningStatusContext
{
    public:
        virtual Miles UpdateMiles(const Miles& miles, int earnedMiles) = 0;
        virtual void UpdateStatus(FrequentFlyers::EarningStatus status) = 0;
};
}
