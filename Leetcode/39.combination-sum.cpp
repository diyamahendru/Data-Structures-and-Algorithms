/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

#include <vector>
using namespace std;

//Backtracking Algorithm
class Solution
{
public:
    void find(int ind, vector<vector<int>> &ans, vector<int> &candidates, vector<int> &curr, int target)
    {
        if (ind == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(curr);
            }

            return;
        }
        
        //Including the current index
        if (candidates[ind] <= target)
        {
            curr.push_back(candidates[ind]);
            find(ind, ans, candidates, curr, target - candidates[ind]);
            curr.pop_back();
        }

        //Moving to next index
        find(ind + 1, ans, candidates, curr, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        find(0, ans, candidates, curr, target);
        return ans;
    }
};
// @lc code=end
