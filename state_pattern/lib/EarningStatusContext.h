#pragma once
#include "IEarningStatus.h"
#include "IEarningStatusContext.h"

#include <map>
#include <memory>

namespace FrequentFlyers
{
    
    class EarningStatusContext : public IEarningStatusContext
    {
        public:
            EarningStatusContext(IEarningStatus* pEarningStatus);
            Miles UpdateMiles(const Miles& miles, int earnedMiles) override;
            void SetStatusLevel(IEarningStatus* pStatus) override;

        private:    
            
            // Null Object Pattern
            class NoneEarningStatus : public IEarningStatus
            {
                public:
                    Miles UpdateMiles(const Miles& miles, int earnedMiles) override
                    {
                        // In debug, we want to assert here. In release, we want 
                        // to just do nothing and return the miles supplied.
                        return miles;
                    }
            };

            IEarningStatus* mpCurrentEarningStatus;
            NoneEarningStatus mDefaultEarningStatus;

    };
}
