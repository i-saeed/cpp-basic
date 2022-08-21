#include "utils.h"
#include <iostream>

namespace utils {

auto createStringMap(const std::string& s) -> std::unordered_map<char, size_t> {
    std::unordered_map<char, size_t> map;
    std::for_each(begin(s), end(s), [&map](const auto c) {
        auto loc = map.find(c);
        if (loc == map.end())
            map.insert({c, 1});
        else
            loc->second = loc->second + 1;
    });

    return map;
}

} // namespace utils
