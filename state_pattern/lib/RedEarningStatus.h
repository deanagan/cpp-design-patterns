#pragma once
#include "IEarningStatus.h"

#include <string>
#include <vector>

namespace FrequentFlyers
{
    class RedEarningStatus : public IEarningStatus
    {
        public:
            Miles UpdateMiles(const Miles& miles, int earnedMiles) override;
    };
}
