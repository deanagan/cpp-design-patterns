#pragma once
#include "EarningStatusDefinition.h"
#include "Miles.h"

namespace FrequentFlyers
{
    class IMilesStatusCalculator
    {
        public:
            virtual FrequentFlyers::EarningStatus NextStatus(const Miles& miles) const = 0;
            virtual ~IMilesStatusCalculator() {}
    };
}
