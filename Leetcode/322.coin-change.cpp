/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;
            for (auto c : coins)
            {
                if (i - c >= 0 && dp[i - c] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end
