/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> dp(n, false);

        dp[0] = true;
        for (int i = 0; i < n; i++)
        {
            for (auto str : wordDict)
            {
                if (s.substr(i, str.size()).compare(str) == 0)
                {
                    dp[i + str.size()] = true;
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end
