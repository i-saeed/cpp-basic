#include "utils.h"
#include <algorithm>
#include <stdexcept>
#include <unordered_map>

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

auto twoSum(const std::vector<int>& nums, int target) -> std::vector<int> {
    std::vector<int> sum_indices(2);

    std::unordered_map<int, int> map;

    auto found =
        std::any_of(begin(nums), end(nums),
                    [&map, &sum_indices, target, i = 0](const auto n) mutable {
                        auto diff = target - n;
                        auto loc  = map.find(diff);
                        if (loc == map.end()) {
                            map.insert({n, i++});
                        } else {

                            sum_indices = std::vector<int>{loc->second, i++};
                        }
                        return loc != map.end();
                    });

    if (!found)
        throw std::runtime_error("Could not find twoSum solution");

    return sum_indices;
}

} // namespace utils
