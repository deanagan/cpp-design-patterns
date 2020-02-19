#include "GoldEarningStatus.h"
#include "Miles.h"
#include "IMilesStatusCalculator.h"

#include <string>


namespace FrequentFlyers
{
     const int GoldEarningStatus::ExtraEarningPercent = 5;     
    Miles GoldEarningStatus::UpdateMiles(const Miles& miles, int earnedMiles)
    {
        Miles updatedMiles;
        
        earnedMiles += ((ExtraEarningPercent / 100) * earnedMiles);
        updatedMiles.TotalAccumulatedMiles = miles.TotalAccumulatedMiles + earnedMiles;
        mStatusCalculator.NextStatus(updatedMiles);
        return updatedMiles;
    }


}
