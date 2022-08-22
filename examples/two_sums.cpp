#include "utils.h"

#include <cassert>
#include <iostream>
#include <vector>

auto main() -> int {

    std::vector<int> nums{2, 7, 11, 15};

    auto target = int{9};

    auto indices = utils::twoSum(nums, target);
    std::cout << "tow sum indices for target: " << target
              << "    are: " << indices[0] << ", " << indices[1] << std::endl;

    std::vector<int> expected{0, 1};
    assert(indices == expected);

    nums     = std::vector<int>{3, 2, 4};
    target   = 6;
    indices  = utils::twoSum(nums, target);
    expected = std::vector<int>{1, 2};
    assert(indices == expected);

    return 0;
}
