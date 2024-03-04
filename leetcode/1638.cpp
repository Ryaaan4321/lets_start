#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countSubstring(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int x = i;
                int y = j;

                int cnt = 0;

                while (x < n && y < m)
                {
                    if (s[x] != s[j] && cnt++ > 2)
                    {
                        break;
                    }
                    ans += cnt;
                    x++;
                    y++;
                }
            }
        }
        return ans;
    }
};
int main()
{

    string s;
    string t;
    cin >> s;
    cin >> t;

    auto ss = Solution();
    auto ans = ss. countSubstring(s,t);

    cout<<ans<<endl;
}