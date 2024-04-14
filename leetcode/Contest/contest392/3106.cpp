#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    string getSmallestString(string s, int k)
    {
        string ans = s;
        for (char &ch : s)
        {
            int left = ch - 'a';
            int right = 'z' - ch + 1;
            int mn = min(left, right);
            if (k >= mn)
            {
                k -= mn;
                ch = 'a';
            }
            else
            {
                ch = ch - k;
                break;
            }
        }
        return s;
    }
};

int main()
{
    string s;
    int k;
    cin >> s;
    cin >> k;

    Solution obj;

    string ans = obj.getSmallestString(s, k);
    cout << ans << endl;
}