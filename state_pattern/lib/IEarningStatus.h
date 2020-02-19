#pragma once
#include "Miles.h"

#include <string>
#include <vector>

namespace FrequentFlyers
{
    class IEarningStatus
    {
        public:
            virtual Miles UpdateMiles(const Miles& miles, int earnedMiles) = 0;
    };
}