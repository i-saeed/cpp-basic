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

auto isAnagram(const std::string& s, const std::string& t) -> bool {
    if (s.size() != t.size())
        return false;

    auto s_map = createStringMap(s);
    auto t_map = createStringMap(t);
    return s_map == t_map;
}

} // namespace utils
