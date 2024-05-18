/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
using namespace std;

#include <unordered_map>
#include <vector>
#include <algorithm>

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for (string x : strs)
        {
            string y = x;
            sort(x.begin(), x.end());
            if (mp.find(x) == mp.end())
                mp[x] = {y};
            else
                mp[x].push_back(y);
        }

        for (auto const &x : mp)
        {
            result.push_back(x.second);
        }

        return result;
    }
};
// @lc code=end
