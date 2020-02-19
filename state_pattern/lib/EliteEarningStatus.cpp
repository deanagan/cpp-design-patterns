#include "EliteEarningStatus.h"
#include "Miles.h"
#include "IMilesStatusCalculator.h"

#include <string>


namespace FrequentFlyers
{
    const int EliteEarningStatus::ExtraEarningPercent = 10;
           
    Miles EliteEarningStatus::UpdateMiles(const Miles& miles, int earnedMiles)
    {
        Miles updatedMiles;
        
        earnedMiles += ((ExtraEarningPercent / 100) * earnedMiles);
        updatedMiles.TotalAccumulatedMiles = miles.TotalAccumulatedMiles + earnedMiles;
        mStatusCalculator.NextStatus(updatedMiles);
        return updatedMiles;
    }


}
