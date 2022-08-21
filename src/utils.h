#ifndef _UTILS_H
#define _UTILS_H

#include <algorithm>
#include <string>
#include <unordered_map>
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
}

auto createStringMap(const std::string& s) -> std::unordered_map<char, size_t>;

auto isAnagram(const std::string& s, const std::string& t) -> bool;

auto twoSum(const std::vector<int>& nums, int target) -> std::vector<int>;

auto isPalindrome(const std::string& s) -> bool;

auto areValidParentheses(const std::string& s) -> bool;

} // namespace utils

#endif
