/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start

//Kadane's algorithm
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN;
        int n = nums.size();
        int tempAns = 1;

        for (int i = 0; i < n; i++)
        {
            tempAns *= nums[i];
            ans = max(ans, tempAns);
            if (tempAns == 0)
                tempAns = 1;
        }

        tempAns = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            tempAns *= nums[i];
            ans = max(ans, tempAns);
            if (tempAns == 0)
                tempAns = 1;
        }

        return ans;
    }
};
// @lc code=end
