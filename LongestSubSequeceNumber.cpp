#include<vector>
#include<iostream>
#include <iterator>
#include <algorithm>
#include <initializer_list>
//time complexity : nlogn
//Space complexity: n
class Solution {
public:
	int lengthOfLIS(std::vector<int>& nums) {
		std::vector<int> res;

		for (int n : nums) {
			if (res.empty() || res.back() < n) {
				res.push_back(n);
			}
			else {
				int idx = binarySearch(res, n);
				res[idx] = n;
			}
		}
		return res.size();
	}
private:
	int binarySearch(const std::vector<int>& arr, int target) {
		int left = 0;
		int right = arr.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] == target) {
				return mid;
			}
			else if (arr[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};

template <typename T>
concept Container = requires(T t) {
	std::begin(t);
	std::end(t);
	typename T::value_type; // Optional: check for value_type
	// Add more requirements as needed, e.g., t.size(), t.empty()
};

template <class T>
std::ostream& operator << (std::ostream& os, std::vector <T> const& x) {
	os << "{ ";
	for (auto& y : x) os << y << " ";
	return os << "}";
}

template <typename C>
void print( C&& data) {
	
	auto it = std::begin(data);
	auto end_it = std::end(data);
	while( it != end_it) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}
/*

template <typename C>
void print(const C& data) {
	for (auto& elem : data)
		std::cout << elem << " ";
	std::cout << std::endl;
}
*/
int main() {
	
	Solution soln;


	//std::vector<int> input{ 10,9,2,5,3,7,101,18 };
	//auto result = soln.lengthOfLIS(input);
	//std::cout << input;
	//std::cout << result << std::endl;
	//print(input);
	std::vector<int> input1{ 0,1,0,3,2,3 };
	auto result = soln.lengthOfLIS(input1);
	std::cout << result << std::endl;
	std::vector<int> input2{ 7,7,7,7,7,7,7 };


	return 0;
}
