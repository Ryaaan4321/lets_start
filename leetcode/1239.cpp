#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxlength(vector<string> &arr)
    {
        unordered_set<int> arrBitSet;
        for (auto word : arr)
            wordToBitSet(arrBitSet, word);
        vector<int> arrAsBits(arrBitSet.begin(), arrBitSet.end());
        return solve1(arrAsBits, 0, 0);
    }

private:
    void wordToBitSet(unordered_set<int> &arrBitSet, string &word)
    {
        int charBitSet = 0;
        for (char &c : word)
        {
            int mask = 1 << (c - 'a');
            if (charBitSet & mask)
                return;
            charBitSet += mask;
        }
        int lenBitSet = word.length() << 26;
        arrBitSet.insert(charBitSet + lenBitSet);
    }
    int solve1(vector<int> &arrAsBits, int i, int res)
    {
        int oldChars = res & ((1 << 26) - 1);
        int oldLen = res << 26;
        int best = oldLen;

        if (i >= arrAsBits.size())
            return best;

        int newChars = arrAsBits[i] & ((1 << 26) - 1);
        if ((!newChars & oldChars))
        {
            int newlen = arrAsBits[i] >> 26;
            int newres = newChars + oldChars + (newlen + oldLen << 26);
            best = max(best, solve1(arrAsBits, i + 1, newres));
        }
        best = max(best, solve1(arrAsBits, i + 1, res));
        return best;
    }

private:
    /*recursion*/
    int solve(vector<string> &arr, int i, string res)
    {
        /*we want the unique characters out of all the substrings so for that using set to store the unique values */
        unordered_set<char> resSet(res.begin(), res.end());
        if (res.size() != resSet.size())
            return 0;

        if (i >= arr.size()) /* and the moment when the i > arr.size or equal to that so return it */
            return res.size();

        int best = res.size();                             /*then what we can do take a best length till now*/
        best = max(best, solve(arr, i + 1, res + arr[i])); /*and what we do in recursion is that either we take the elm or not so here i am takiing it */
        best = max(best, solve(arr, i + 1, res));          /* and here not and in both the condition it will be checked by the set that they r unq
        or not if they are then we will move forward
                  or either we willl stop and return the best*/
        return best;
    };

private:
    /* backtracking */
    int solve2(vector<string> &arr, int i, string res)
    {
        unordered_set<char> resSet(res.begin(), res.end());
        if (res.size() != resSet.size())
            return 0;

        if (i >= arr.size())
            return res.size();

        int best = res.size();
        for (auto c : arr[i])
            res.push_back(c);

        best = max(best, solve(arr, i + 1, res));
        for (auto c : arr[i])
            res.pop_back();
        best = max(best, solve(arr, i + 1, res));

        return best;
    }
};