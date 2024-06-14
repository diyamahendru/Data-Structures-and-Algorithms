/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

// Kadane's algorithm
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxCurr = 0;
        int maxTotal = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            maxCurr = max(0, maxCurr += (prices[i] - prices[i - 1])); // If maxCurr becomes -ve, we set it to 0.
            //For a strictly increasing subsequence, maxCurr will be prices[end]-prices[start].
            maxTotal = max(maxCurr, maxTotal);
            //It will simultaneously also update maxTotal to max so far.
        }

        return maxTotal;
    }
};
// @lc code=end
