/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]

Complexity
Time complexity: O(3^n) or O(4^n)
n is length of input string. Each digit has 3 or 4 letters. For example, if you get "23"(n) as input string, we will create 9 combinations which is O(3^2) = 9

Space complexity: O(n)
n is length of input string. This is for recursive call stack.
*/
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>

class Solution {
public:
	std::vector<std::string> letterCombinations(std::string digits) {
		
		std::vector<std::string> res;

		if (digits.empty()) {
			return res;
		}

		std::unordered_map<char, std::string> digitToLetters = {
			{'2',"abc"},
			{'3',"def"},
			{'4',"ghi"},
			{'5',"jkl"},
			{'6',"mno"},
			{'7',"pqrs"},
			{'8',"tuv"},
			{'9',"wxyz"}
		};

		backtrack(digits, 0, "", res, digitToLetters);

		return res;
	}

	void backtrack(const std::string& digits, int idx, std::string comb,
		std::vector<std::string>& res,
		const std::unordered_map<char, std::string>& digitToLetters)
	{
			if (idx == digits.length()) {
				res.push_back(comb);
				return;
			}
			//std::cout << " value at digits[" << idx << "] is " << digits[idx] << std::endl;
			std::string letters = digitToLetters.at(digits[idx]);
			for (char letter : letters) {
				backtrack(digits, idx + 1, comb + letter, res, digitToLetters);
			}
	}
	
};

int main() {

	Solution soln;
	auto  result = soln.letterCombinations("23");
	for (const auto& res : result)
		std::cout << res << std::endl;

	return 0;


}
