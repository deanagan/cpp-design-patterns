#include "RedEarningStatus.h"
#include "Miles.h"
#include "IMilesStatusCalculator.h"

#include <string>


namespace FrequentFlyers
{
    RedEarningStatus::RedEarningStatus(const IMilesStatusCalculator& statusCalculator)
        : mStatusCalculator(statusCalculator)
    {

    }

    Miles RedEarningStatus::UpdateMiles(const Miles& miles, int earnedMiles)
    {
        Miles updatedMiles;
        
        updatedMiles.TotalAccumulatedMiles = miles.TotalAccumulatedMiles + earnedMiles;
        updatedMiles.Level = "Red";
        return updatedMiles;
    }


}
