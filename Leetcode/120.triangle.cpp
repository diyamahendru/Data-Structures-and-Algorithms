/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int minSum = triangle[0][0];
        int prevIdx = 0;
        for (int i = 1; i < n; i++)
        {
            if (triangle[i][prevIdx] < triangle[i][prevIdx + 1])
            {
                minSum += triangle[i][prevIdx];
            }
            else
            {
                minSum += triangle[i][prevIdx + 1];
                prevIdx++;
            }
        }

        return minSum;
    }
};
// @lc code=end
