#pragma once
#include "EarningStatusDefinition.h"
#include "Miles.h"
#include "IMilesStatusCalculator.h"

namespace FrequentFlyers
{
    class MilesStatusCalculator : public IMilesStatusCalculator
    {
        public:
            FrequentFlyers::EarningStatus NextStatus(const Miles& miles) const override;
    };
}
