/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<pair<int, int>> stk;
        heights.push_back(0);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while (!stk.empty() && stk.top().second > heights[i])
            {
                auto [idx, val] = stk.top();
                stk.pop();
                max_area = max(max_area, val * (i - idx));
                start = idx;
            }
            stk.push(make_pair(start, heights[i]));
        }

        return max_area;
    }
};
// @lc code=end

/* Algorithm - Idea behind this algo is we continue pushing in the stack if the new element is equal or greater than the stack top. 
    This means current element smaller than the new element has the potential of expanding further.

    Worse Case - O(n^2)

1. Start by pushing an 0 in the heights array in the end in order to compute strictly increasing arrays.
2. Set max_area as 0 and start looping through the array.
3. If the stk is empty or, the top element is less than new element, push the index and new element in the stk.
4. If the top of the stack is greater than new element, we start popping the stack's top till the stack's top is not equal or less than new element.
5. At each pop, we re-calculate the max area and update the starting index for the new element. 
*/