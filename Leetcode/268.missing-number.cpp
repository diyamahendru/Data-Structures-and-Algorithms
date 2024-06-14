/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include<vector>
using namespace std;

//Arithmetic Progression technique
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int x : nums){
            sum+= x;
        }

        return n*(n+1)/2 - sum;
    }
};
// @lc code=end

