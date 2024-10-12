#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    /*And one day evrything got changed and he became his own companion;*/
    /*chcking if the characters is in the string or not */
    bool checkRepition(string s, int start, int end)
    {
        unordered_set<char> ch;
        for (int i = start; i < end; ++i)
        {
            char c = s[i];
            if (ch.count(c))
            {
                return false;
            }
        }
        return true;
    }
    int lengthOfLongestSubstring2(string s)
    {
        unordered_map<char, int> map;
        int ans = 0;
        for (int j = 0, i = 0; j < s.length(); ++j)
        {
            if (map[s[i]] > 0)
            {
                i = max(map[s[j]], i);
            }
            ans = max(ans, j - i + 1);
            map[s[j]] = j + 1;
        }
        return ans;
    }
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = i; j < s.length(); ++j)
            {
                if (checkRepition(s, i, j))
                {
                    ans = max(ans, j - i + 1);
                }
                /*now because we are iterating with the three lopps soo it can end up giving us the  time limit exceededd*/
            }
        }
        return ans;
    }
   int lengthOfLongestSubstring(string s) {
        int hash[255]={-1};
        int cnt=0;int mcnt=0;
        int l=0;int r=0;
        while(r<(int)s.length()){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=max(hash[s[r]]+1,l);
                    cnt=r-l+1;
                    mcnt=max(cnt,mcnt);
                }
            }else{
                hash[s[r]]++;
                r++;
            }
        }
        return mcnt;
    }
};