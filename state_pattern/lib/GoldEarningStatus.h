#pragma once
#include "IEarningStatus.h"

#include <string>
#include <vector>

namespace FrequentFlyers
{
    
    class GoldEarningStatus : public IEarningStatus
    {
        public:
            Miles UpdateMiles(const Miles& miles, int earnedMiles) override;
        private:
            static const int ExtraEarningPercent;
    };
}
