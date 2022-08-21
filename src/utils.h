#ifndef _UTILS_H
#define _UTILS_H

#include <algorithm>
#include <unordered_set>
#include <vector>

namespace utils {

template <typename T>
auto containsDuplicate(const std::vector<T>& nums) -> bool {
    auto                  contains = bool{false};
    std::unordered_set<T> hash_map;

    return std::any_of(begin(nums), end(nums), [&hash_map](const auto& n) {
        const auto contains = (hash_map.find(n) != hash_map.end());
        if (!contains) {
            hash_map.insert(n);
        }
        return contains;
    });
};

} // namespace utils

#endif
