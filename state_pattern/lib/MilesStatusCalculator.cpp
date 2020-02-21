#include "MilesStatusCalculator.h"

namespace FrequentFlyers
{
    const int MilesStatusCalculator::GOLD_THRESHOLD = 200;
    
    FrequentFlyers::EarningStatus MilesStatusCalculator::NextStatus(const Miles& miles) const
    {
        auto status = FrequentFlyers::EarningStatus::RED;
        
        if (miles.TotalAccumulatedMiles > GOLD_THRESHOLD)
        {
            status = FrequentFlyers::EarningStatus::GOLD;
        }
        
        return status;
    }
}