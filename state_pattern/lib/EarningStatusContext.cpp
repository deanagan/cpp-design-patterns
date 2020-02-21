#include "EarningStatusContext.h"
#include "RedEarningStatus.h"
#include "GoldEarningStatus.h"

namespace FrequentFlyers
{
    EarningStatusContext::EarningStatusContext()
        : mCurrentStatus(FrequentFlyers::EarningStatus::RED)
    {
        mEarningStatus[EarningStatus::RED] = std::make_unique<RedEarningStatus>(mStatusCalculator);
        mEarningStatus[EarningStatus::GOLD] = std::make_unique<GoldEarningStatus>(mStatusCalculator);
    }

    Miles EarningStatusContext::UpdateMiles(const Miles& miles, int earnedMiles)
    {
        const auto updatedMiles = mEarningStatus[mCurrentStatus]->UpdateMiles(miles, earnedMiles);
        mCurrentStatus = mStatusCalculator.NextStatus(updatedMiles);
        return updatedMiles;
    }

} 
