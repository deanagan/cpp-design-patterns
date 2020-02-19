#pragma once
#include "IEarningStatus.h"
#include "IEarningStatusContext.h"
#include "MilesStatusCalculator.h"

#include <map>
#include <memory>

namespace FrequentFlyers
{
    
    class EarningStatusContext : public IEarningStatusContext
    {
        public:
            EarningStatusContext();
            Miles UpdateMiles(const Miles& miles, int earnedMiles) override;
            void UpdateStatus(FrequentFlyers::EarningStatus status) override;
        private:
            FrequentFlyers::EarningStatus mCurrentStatus;
            MilesStatusCalculator mStatusCalculator;
            std::map<FrequentFlyers::EarningStatus, std::unique_ptr<IEarningStatus>> mEarningStatus;
            
    };
}
