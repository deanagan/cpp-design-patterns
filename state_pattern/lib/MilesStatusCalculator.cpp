#include "MilesStatusCalculator.h"

namespace FrequentFlyers
{
    FrequentFlyers::EarningStatus MilesStatusCalculator::NextStatus(const Miles& miles) const
    {
        auto status = FrequentFlyers::EarningStatus::RED;
        
        if (miles.TotalAccumulatedMiles > 200)
        {
            status = FrequentFlyers::EarningStatus::GOLD;
        }
        else if (miles.TotalAccumulatedMiles > 500)
        {
            status = FrequentFlyers::EarningStatus::ELITE;
        }

        return status;
    }
}