#include "utils.h"

#include <cassert>
#include <iostream>
#include <string>

auto main() -> int {

    std::string s{"A man, a plan, a canal: Panama"};
    bool        expected{true};
    auto        found = utils::isPalindrome(s);
    assert(found == expected);

    s        = {"race a car"};
    expected = false;
    found    = utils::isPalindrome(s);
    assert(found == expected);

    s        = " ";
    expected = true;
    found    = utils::isPalindrome(s);
    assert(found == expected);

    return 0;
}
