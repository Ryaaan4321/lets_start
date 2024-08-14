#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool isvalid(string s)
    {
        int z = count(s.begin(), s.end(), '0');
        int o = count(s.begin(), s.end(), '1');
        if(z!=o){
            return 0;
        }
        for(int i=0;i<z;i++){
            if(s[i]!=0){
                return 0;
            }
        }
        return 1;
    }
    int findTheLongestBalancedSubstring(string s)
    {
       
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            string str;
            for (int j = i; j < n; i++)
            {
                str += s[j];
                if (isvalid(str))
                {
                    ans = max(ans, (int)str.size());
                }
            }
        }
        return ans;
    }
};