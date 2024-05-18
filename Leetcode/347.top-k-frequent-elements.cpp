/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> heap;
        vector<int> res(k, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (mp.find(x) == mp.end())
                mp[x] = 1;
            else
                mp[x]++;
        }

        for (auto const &x : mp)
        {
            heap.push(make_pair(x.second, x.first));
        }

        while (heap.size() != 0 && k>0)
        {
            int val = heap.top().second;
            res[--k] = val;
            heap.pop();
        }

        return res;
    }
};
// @lc code=end
