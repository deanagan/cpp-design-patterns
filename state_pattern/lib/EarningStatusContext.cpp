#include "EarningStatusContext.h"
#include "RedEarningStatus.h"
#include "GoldEarningStatus.h"
#include "EliteEarningStatus.h"

namespace FrequentFlyers
{
    EarningStatusContext::EarningStatusContext()
        : mCurrentStatus(FrequentFlyers::EarningStatus::RED)
    {
        mEarningStatus[EarningStatus::RED] = std::make_unique<RedEarningStatus>(mStatusCalculator);
        mEarningStatus[EarningStatus::GOLD] = std::make_unique<GoldEarningStatus>(mStatusCalculator);
        mEarningStatus[EarningStatus::ELITE] = std::make_unique<EliteEarningStatus>(mStatusCalculator);
    }

    Miles EarningStatusContext::UpdateMiles(const Miles& miles, int earnedMiles)
    {
        return mEarningStatus[mCurrentStatus]->UpdateMiles(miles, earnedMiles);
    }

    void EarningStatusContext::UpdateStatus(FrequentFlyers::EarningStatus status)
    {
        mCurrentStatus = status;
    }
} 
