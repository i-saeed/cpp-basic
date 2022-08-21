#include "utils.h"
#include <iostream>
#include <stdexcept>

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

    auto found = bool{false};

    for (size_t i = 0; i < nums.size(); ++i) {
        for (auto j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                sum_indices[0] = i;
                sum_indices[1] = j;
                found          = true;
                break;
            }
        }
        if (found)
            break;
    }
    if (!found)
        throw std::runtime_error("Could not find twoSum solution");

    return sum_indices;
}

} // namespace utils
