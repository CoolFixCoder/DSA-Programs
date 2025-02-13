/*

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]

Output: 4
Example 3:

Input: nums = [1]

Output: 1
  */

#include <iostream>
#include<vector>


class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i]; 
        }
        return result;
    }
   
};

//C++20
template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v)
{
    s.put('{');
    for (char comma[]{ '\0', ' ', '\0' }; const auto & e : v)
       s << comma << e, comma[0] = ',';
    //for (const auto& e : v)
       // s << e << " ,";
    return s << "}\n";
}

int main()
{
    //std::vector<int> nums1 = { 2,2,1};
    std::vector<int> nums1 = { 4, 1, 2, 1, 2 };

    std::cout << "First vector contain values are:  " << nums1;
    
   
    Solution soln;
    auto number =  soln.singleNumber(nums1);

    std::cout << "Value " << number<< " is Single Number in a given vector "<<nums1<<" with an unique number"<<std::endl;

    return 0;

}
