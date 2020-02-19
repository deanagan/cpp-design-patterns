#pragma once
#include "IEarningStatus.h"

#include <string>
#include <vector>

namespace FrequentFlyers
{
    class IMilesStatusCalculator;
    class RedEarningStatus : public IEarningStatus
    {
        public:
            explicit RedEarningStatus(const IMilesStatusCalculator&  statusCalculator);
            Miles UpdateMiles(const Miles& miles, int earnedMiles) override;
        private:
            const IMilesStatusCalculator& mStatusCalculator;
    };
}
