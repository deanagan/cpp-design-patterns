#include "EarningStatusContext.h"


namespace FrequentFlyers
{
    EarningStatusContext::EarningStatusContext(IEarningStatus* pDefaultEarningStatus)
        : mpCurrentEarningStatus((pDefaultEarningStatus != nullptr) ? pDefaultEarningStatus : &mDefaultEarningStatus)
    {
    }

    Miles EarningStatusContext::UpdateMiles(const Miles& miles, int earnedMiles)
    {
        return mpCurrentEarningStatus->UpdateMiles(miles, earnedMiles);
    }

    void EarningStatusContext::SetStatusLevel(IEarningStatus* pStatus)
    {
        mpCurrentEarningStatus = pStatus;
    }

} 
