/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();

        int total = n1 + n2;
        int half = (n1 + n2) / 2;

        int left = 0;
        int right = n1;

        while (left <= right)
        {
            int amid = (left + right) / 2; // Median of a
            int bmid = half - amid;    // Assumed median of b

            int aleft = (amid < 0 ? INT_MIN : nums1[amid]);
            int aright = (amid + 1 >= n1 ? INT_MAX : nums1[amid + 1]);
            int bleft = (bmid < 0 ? INT_MIN : nums2[bmid]);
            int bright = (bmid + 1 >= n2 ? INT_MAX : nums2[bmid + 1]);

            if (max(aleft, bleft) <= min(aright, bright))
            {
                // Partiton is correct.
                // If Odd total
                if (total % 2 == 1)
                    return min(aleft, bleft);
                else
                    return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            }
            else if (aleft > bright)
            {
                right = amid - 1;
            }
            else
            {
                left = amid + 1;
            }
        }

        return 0.0;
    }
};
// @lc code=end
