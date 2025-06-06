//122. Best Time to Buy and Sell Stock II
// Complexity
//Time complexity : O(n)
//Space complexity : O(1)
int maxProfit(std::vector<int>& prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += (prices[i] - prices[i - 1]);
        }
    }
    return profit;
}
int main()
{
//Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//Output : [5, 6, 7, 1, 2, 3, 4]
    std::vector<int> nums{ 7,1,5,3,6,4 };
    auto profit = maxProfit(nums);
   std::cout << profit << std::endl;

   return 0;
}
