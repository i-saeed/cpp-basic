#include "utils.h"

#include <cassert>
#include <iostream>
#include <string>

auto main() -> int {
    std::string s{"anagram"};
    std::string t{"nagaram"};

    std::cout << "s: " << s << ",  t: " << t
              << ",   are anagrams: " << std::boolalpha
              << utils::isAnagram(s, t) << std::endl;

    assert(utils::isAnagram(s, t));

    s = "rat";
    t = "car";
    assert(!utils::isAnagram(s, t));

    std::cout << "s: " << s << ",  t: " << t
              << ",   are anagrams: " << std::boolalpha
              << utils::isAnagram(s, t) << std::endl;

    return 0;
}
