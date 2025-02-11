/*
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

 int searchIndex(const std::vector<int>& array, const int target)
{
    int left = 0;
    int right = array.size() - 1;

    // Binary Search
    while (left <= right)
    {
        //Find the middle element
        auto mid = (left + right) / 2;
        
        if (array[mid] == target)
            return mid;
        else if (array[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}


int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> values = { -1, 0, 3, 5, 9, 12 };
    int findIndexOfElement = 0;
     auto index = searchIndex(values,findIndexOfElement);

    if (index == -1)
        std::cout << findIndexOfElement << " does not exist in array of values" << std::endl;
    else
        std::cout << findIndexOfElement << " exists in values and its index is " << index << std::endl;

    return 0;

}
