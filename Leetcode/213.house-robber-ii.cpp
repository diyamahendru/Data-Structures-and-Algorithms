/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
// Top Down Approach
class Solution
{
public:
    int solve(vector<int> &nums, int i, int endi, vector<int> &dp)
    {
        if (i > endi)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans1 = solve(nums, i + 1, endi, dp);           // exclude the current element
        int ans2 = nums[i] + solve(nums, i + 2, endi, dp); // include the current element
        dp[i] = max(ans1, ans2);

        return dp[i];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = solve(nums, 0, n - 2, dp1);
        int case2 = solve(nums, 1, n - 1, dp2);

        return max(case1, case2);
    }
};
// @lc code=end
