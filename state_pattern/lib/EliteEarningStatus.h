#pragma once
#include "IEarningStatus.h"

#include <string>
#include <vector>

namespace FrequentFlyers
{
    class IMilesStatusCalculator;
    class EliteEarningStatus : public IEarningStatus
    {
        public:
            explicit EliteEarningStatus(const IMilesStatusCalculator&  statusCalculator);
            Miles UpdateMiles(const Miles& miles, int earnedMiles) override;
        private:
            const IMilesStatusCalculator& mStatusCalculator;
            
            static const int ExtraEarningPercent;
    };
}
