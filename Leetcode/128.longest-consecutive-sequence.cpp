/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        int largest = 0;

        for (auto num : nums)
        {
            st.insert(num);
        }

        for (auto element : st)
        {
            int parent = element - 1;

            if (st.find(parent) == st.end())
            {
                int nextElement = element + 1;
                int cnt = 1;

                while (st.find(nextElement) != st.end())
                {
                    nextElement++;
                    cnt++;
                }

                if (cnt > largest)
                    largest = cnt;
            }
        }

        return largest;
    }
};
// @lc code=end
