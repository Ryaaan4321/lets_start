#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    bool checkString(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (s[i] == s[j])
                i++, j--;
            else
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string> &words)
    {
        for(int i=0;i<words.size();++i){
            if(checkString(words[i])){
                return words[i];
            }
        }
        return "";
    }
};