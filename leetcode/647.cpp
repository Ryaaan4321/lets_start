#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
    public:
    int palindromicCount(string &s, int i, int j)
    {
        int count = 0;
        while (i >= 0 && j <= s.size() && s[i] == s[j])
        {
            i--;
            j++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s)
    {
        int count = 0, n = s.size();
        for (int i = 0; i < n; ++i)
        {
            int even = palindromicCount(s, i, i + 1);
            int odd = palindromicCount(s, i, i);
        }
        return count;
    }
};
int main(){
    string s="aaraa";
    Solution obj;
    int ans=obj.countSubstrings(s);
    cout<<ans<<endl;
}