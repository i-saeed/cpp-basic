#include "utils.h"

#include <cassert>
#include <iostream>
#include <vector>

auto main() -> int {

    std::vector<int> prices{7, 1, 5, 3, 6, 4};

    auto profit   = utils::maxProfit(prices);
    auto expected = int{5};
    assert(profit == expected);

    prices   = {7, 6, 4, 3, 1};
    profit   = utils::maxProfit(prices);
    expected = 0;
    assert(profit == expected);

    prices   = {2, 4, 1};
    profit   = utils::maxProfit(prices);
    expected = 2;
    assert(profit == expected);

    return 0;
}
