/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int traverse(vector<vector<int>> &paths, int m, int n)
    {
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                paths[i][j] += paths[i - 1][j] + paths[i][j - 1];
            }
        }

        return paths[m - 1][n - 1];
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> paths(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            paths[i][0] = 1;
        for (int j = 0; j < n; j++)
            paths[0][j] = 1;
        int res = traverse(paths, m, n);

        return res;
    }
};
// @lc code=end
