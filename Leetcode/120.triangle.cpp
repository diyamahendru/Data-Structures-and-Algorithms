/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

// Top down approach
class Solution
{
public:
    int solve(vector<vector<int>> &tri, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (i == n - 1)
            return tri[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = tri[i][j] + solve(tri, n, i + 1, j, dp);
        int diagonal = tri[i][j] + solve(tri, n, i + 1, j + 1, dp);
        dp[i][j] = min(down, diagonal);

        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int minsum = solve(triangle, n, 0, 0, dp);

        return minsum;
    }
};
// @lc code=end
