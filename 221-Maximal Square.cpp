/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0

Time Complexity : O(MN)
Space Complexity : O(MN)
*/


#include<iostream>
#include<vector>
#include<algorithm>

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
/*
class Solution
{
public:
    int maximalSquare(std::vector<std::vector<char>>& M) {
        int m = size(M), n = size(M[0]), ans = 0;
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = m - 1; ~i; --i)
            for (int j = n - 1; ~j; --j)
            {
                dp[i][j] = (M[i][j] == '1' ? 1 + std::min({ dp[i + 1][j],dp[i][j + 1],dp[i + 1][j + 1] }) : 0);
                ans = std::max(ans, dp[i][j]);
            }

        return ans * ans;
    }
};
*/

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& M) {
        int m = size(M), n = size(M[0]), ans = 0;
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));
        for(int i = m-1; ~i; i--)
            for(int j = n-1; ~j; j--) 
                dp[i][j] = (M[i][j] == '1' ? 1 + std::min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}) : 0),
                ans = std::max(ans, dp[i][j]);

        return ans * ans;
    }
};


/*
Time Complexity : O(MN)
Space Complexity : O(N), this can be further optimized to O(min(M, N)) as well.

Solution - V (Space-Optimized Dynamic Programming)

We can see that we are only ever accessing the current row and next row of dp. Thus we dont need to store every row of it 
and can do away with only storing two rows.

A common and easy way to convert 2D dp to linear space usage is by defining 2 rows in dp and 
alternating between those rows for each computation. This basically ensures we are using 
previous computed row to compute the current row and we dont even need to change the previous solution by much. 
We can simply alternate between rows using the mod 2(%2) or AND 1 (& 1) operations.

Thus, we can optmize on space as below -

C++

class Solution {
public:
    int maximalSquare(vector<vector<char>>& M) {
        int m = size(M), n = size(M[0]), ans = 0;
        vector<vector<int>> dp(2, vector<int>(n+1));
        for(int i = m-1; ~i; i--)
            for(int j = n-1; ~j; j--)
                dp[i&1][j] = (M[i][j] == '1' ? 1 + min({dp[(i+1)&1][j], dp[i&1][j+1], dp[(i+1)&1][j+1]}) : 0),
                ans = max(ans, dp[i&1][j]);

        return ans * ans;
    }
};




*/
int main()
{
    std::vector<std::vector<char>> input = {
                                            {'1','0','1','0','0'},
                                            {'1','0','1','1','1'},
                                            {'1','1','1','1','1'},
                                            {'1','0','0','1','0'} 
                                            };

    Solution soln;

    auto result = soln.maximalSquare(input);
    std::cout << " Result = " << result << std::endl;


    return 0;
}
