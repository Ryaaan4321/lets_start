#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    static bool isVowel(char c)
    {
        string s = "aeiou";
        // int c = 0;
        if (s.find(c) != string::npos)
            return true;
        ;
        return false;
    }
    static bool halvesAreAlike(string s)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        int length = s.length();
        int mid = s.length() / 2;
        string first = s.substr(0, mid);
        string last = s.substr(mid, s.length());
        for (char c : first)
        {
            if (isVowel(c))
            {
                cnt1++;
            }
        }
        for (char c : last)
        {
            if (isVowel(c))
            {
                cnt2++;
            }
        }

       if(cnt1==cnt2) return true;
       return false;
    }
};


int main()
{
    string s;
    cin >> s;
    Solution obj;
    bool ans = obj.halvesAreAlike(s);
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}