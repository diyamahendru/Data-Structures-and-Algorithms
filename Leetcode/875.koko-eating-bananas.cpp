/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start

#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int getMax(vector<int> piles)
    {
        int max = INT_MIN;
        for (int x : piles)
        {
            if (x > max)
                max = x;
        }

        return max;
    }

    int getTotalHours(vector<int> piles, int rate)
    {
        int total = 0;

        for (int x : piles)
        {
            total += ceil(x / rate);
        }

        return total;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int max = getMax(piles);
        int start = 1;
        int end = max;

        int ans = 0;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int totalHours = getTotalHours(piles, mid);

            if (totalHours = h)
                return mid;
            else if (totalHours > h)
                start = mid + 1;
            else
            {
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }
};
// @lc code=end
