#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right && s[left] == s[right])
        {
            char c = s[left];
            while (left < right && s[left] == c)
                left++;
            while (left <= right && s[right] == c)
                right--;

            /* code */
        }
        return right-left+1;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution obj;
    int ans = obj.minimumLength(s);
    cout << ans << endl;
    return 0;
}