/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Complexity
Time complexity: O(n)
Space complexity: O(n)

*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>

template<typename C>
void print(C&& data)
{
    auto it = std::begin(data);
    auto it_end = std::end(data);
    while (it != it_end)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int>  hash;
        int res = 0;
        int majority = 0;
        for (const auto n : nums)
        {
            hash[n] = 1 + hash[n];
            std::cout << "hash[" << n << "]" << hash[n] << " = " << 1 + hash[n] << std::endl;
            if (hash[n] > majority) {
                res = n;
                majority = hash[n];
            }
        }
        for (const auto& kv : hash)
            std::cout << "key = " << kv.first << "  value = " << kv.second << std::endl;

        return res;
    }
    
};


int main() {
    std::vector<int> values = { 3,2,3 };
    print(values);
    Solution soln;
    auto res = soln.majorityElement(values);
    std::cout << "Majority element = "<<res << std::endl;
    
    return 0;
}
