/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
using namespace std;
#include <unordered_map>

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> map;

        for (char x : s)
        {
            if (map.find(x) == map.end())
                map[x] = 1;
            else
                map[x]++;
        }

        for (char x : t)
        {
            if (map.find(x) == map.end() || map[x] <= 0)
                return false;
            else
                map[x]--;
        }

        return true;
    }
};
// @lc code=end
