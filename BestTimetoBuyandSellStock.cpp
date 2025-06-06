//121. Best Time to Buy and Sell Stock
// Complexity
//Time complexity : O(n)
//Space complexity : O(1)
int maxProfit(std::vector<int>& prices)
{
    int buy_price = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); ++i)
    {
        if (buy_price > prices[i])
        {
            buy_price = prices[i];
        }
         profit = std::max(profit, prices[i] - buy_price);
    }
    return profit ;
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
