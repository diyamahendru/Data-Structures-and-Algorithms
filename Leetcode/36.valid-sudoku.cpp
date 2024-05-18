/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, set<char>> row_mp;
        unordered_map<int, set<char>> col_mp;
        unordered_map<int, set<char>> blk_mp;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {   
                    if (row_mp[i].find(board[i][j]) == row_mp[i].end())
                        row_mp[i].insert(board[i][j]);
                    else
                        return false;
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (col_mp[i].find(board[j][i]) == col_mp[i].end())
                        col_mp[i].insert(board[j][i]);
                    else
                        return false;
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int idx = 3 * (i / 3) + (j / 3);
                    if (blk_mp[idx].find(board[i][j]) == blk_mp[idx].end())
                        blk_mp[idx].insert(board[i][j]);
                    else
                        return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end
