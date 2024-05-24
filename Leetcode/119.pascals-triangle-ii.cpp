/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1, 1};
        vector<int> res(rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; i++)
        {
            for (int j = i; j > 0; j--)
            {
                res[j] += res[j - 1];
            }
        }

        return res;
    }
};
// @lc code=end
