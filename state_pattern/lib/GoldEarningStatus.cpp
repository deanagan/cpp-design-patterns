#include "GoldEarningStatus.h"
#include "Miles.h"

#include <string>
#include <memory>

namespace FrequentFlyers
{
    const int GoldEarningStatus::ExtraEarningPercent = 5;     

    Miles GoldEarningStatus::UpdateMiles(const Miles& miles, int earnedMiles)
    {
        Miles updatedMiles;
        
        earnedMiles += ((ExtraEarningPercent * earnedMiles) / 100);
        updatedMiles.TotalAccumulatedMiles = miles.TotalAccumulatedMiles + earnedMiles;
        updatedMiles.Level = "Gold";
        return updatedMiles;
    }

}
