#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    void solve(int open, int close, vector<string> &res, string s)
    {
        if (open == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }
        if (open > 0)
        {
            solve(open - 1, close, res, s + "(");
        }
        if (close > 0 && close > open)
        {
            solve(open, close - 1, res, s + ")");
        }
    }
    void tryCombination(int open, int close, vector<string> &res, string s)
    {
        if (open == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }
        if (open > 0)
        {
            s.push_back('(');
            tryCombination(open - 1, close, res, s);
            s.pop_back();
        }
        if (close > 0 && close > open)
        {
            s.push_back(')');
            tryCombination(open, close - 1, res, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        solve(n, n, result, "");
        return result;
    }
};