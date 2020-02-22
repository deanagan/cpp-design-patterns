#include "RedEarningStatus.h"
#include "Miles.h"

#include <string>


namespace FrequentFlyers
{
    Miles RedEarningStatus::UpdateMiles(const Miles& miles, int earnedMiles)
    {
        Miles updatedMiles;
        
        updatedMiles.TotalAccumulatedMiles = miles.TotalAccumulatedMiles + earnedMiles;
        updatedMiles.Level = "Red";
        return updatedMiles;
    }


}
