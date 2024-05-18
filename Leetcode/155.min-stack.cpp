/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <stack>
using namespace std;

class MinStack
{
    stack<pair<int, int>> stk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stk.empty())
            stk.push(make_pair(val, val));
        else if (stk.top().second > val)
            stk.push(make_pair(val, val));
        else
            stk.push(make_pair(val, stk.top().second));
    }

    void pop()
    {
        stk.pop();
    }

    int top()
    {
        return stk.top().first;
    }

    int getMin()
    {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
