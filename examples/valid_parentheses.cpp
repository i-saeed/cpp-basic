#include "utils.h"

#include <cassert>
#include <iostream>
#include <string>

auto main() -> int {

    std::string s{"()[]{}"};
    bool        expected{true};
    auto        found = utils::areValidParentheses(s);
    assert(found == expected);

    s        = {"()"};
    expected = true;
    found    = utils::areValidParentheses(s);
    assert(found == expected);

    s        = "(]";
    expected = false;
    found    = utils::areValidParentheses(s);
    assert(found == expected);

    return 0;
}
