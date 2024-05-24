/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void eraseIsland(vector<vector<char>> &grid, int n, int m, int i, int j)
    {
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        eraseIsland(grid, n, m, i - 1, j);
        eraseIsland(grid, n, m, i + 1, j);
        eraseIsland(grid, n, m, i, j - 1);
        eraseIsland(grid, n, m, i, j + 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int n = grid.size();
        int m = n ? grid[0].size() : 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    eraseIsland(grid, n, m, i, j);
                }
            }
        }

        return islands;
    }
};
// @lc code=end
