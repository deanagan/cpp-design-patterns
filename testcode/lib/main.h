#pragma once

#include <vector>

namespace TestCode
{
    class MathOp {
    public:
        int Sum(int x, int y) const;
        int NearestValue(const std::vector<int>& numbers, int search) const;
    };
}
