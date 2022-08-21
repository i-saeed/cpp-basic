#include "utils.h"

#include <ios>
#include <iostream>
#include <vector>

auto main() -> int {

    std::vector<int> v1{1, 2, 3, 1};
    std::cout << "v1 contains duplicate: " << std::boolalpha
              << utils::containsDuplicate(v1) << std::endl;

    std::vector<int> v2{1, 2, 3, 4};
    std::cout << "v2 contains duplicate: " << std::boolalpha
              << utils::containsDuplicate(v2) << std::endl;

    std::vector<int> v3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::cout << "v3 contains duplicate: " << std::boolalpha
              << utils::containsDuplicate(v3) << std::endl;

    return 0;
}
