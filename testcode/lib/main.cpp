#include "main.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>

namespace TestCode
{
    int MathOp::Sum(int x, int y) const {
        return x + y;
    }

    int MathOp::NearestValue(const std::vector<int>& numbers, int search) const {
        std::vector<int> sortedNumbers(numbers);
        std::sort(begin(sortedNumbers), end(sortedNumbers), [search](int a, int b) -> bool {
            const auto adiff = std::abs(a - search);
            const auto bdiff = std::abs(b - search);

            const auto res = (adiff - bdiff);
            if (res == 0) {
                return a < b;
            }

            return adiff < bdiff;
        });
        return sortedNumbers.front();
    }
}

int main()
{
    std::vector<int> sortedNumbers{4, 7, 10, 11, 12, 17};

    int search = 9;

    std::sort(begin(sortedNumbers), end(sortedNumbers), [search](int a, int b) -> bool {
            const auto adiff = std::abs(a - search);
            const auto bdiff = std::abs(b - search);

            const auto res = (adiff - bdiff);
            if (res == 0) {
                return a < b;
            }
            std::cout << "{" << a << "," << b << "}\n";
            return adiff < bdiff;
        });
        std::copy(begin(sortedNumbers), end(sortedNumbers), std::ostream_iterator<int>(std::cout, ", ") );
}
