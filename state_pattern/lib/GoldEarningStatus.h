#pragma once
#include "IEarningStatus.h"

#include <string>
#include <vector>

namespace FrequentFlyers
{
    class IMilesStatusCalculator;
    class GoldEarningStatus : public IEarningStatus
    {
        public:
            explicit GoldEarningStatus(const IMilesStatusCalculator&  statusCalculator);
            Miles UpdateMiles(const Miles& miles, int earnedMiles) override;
        private:
            const IMilesStatusCalculator& mStatusCalculator;

            static const int ExtraEarningPercent;
    };
}
