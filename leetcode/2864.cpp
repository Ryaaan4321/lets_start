#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
int n;
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        n = s.length();
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            if (s[left] == '1')
                left++;
            if (s[right] == '0')
                right--;

            if (left <= right && s[left] == '0' && s[right] == '1')
            {
                swap(s[left], s[right]);
            }
        }
        swap(s[left - 1], s[n - 1]);
        return s;
    }

    string maximumOddBinaryNumber1(string s)
    {
        int cnt = 0;
        n = s.length();
        for (auto c : s)
        {
            if (c == 1)
                cnt++;
        }
        string ans = string(cnt - 1, '1') + string(n - cnt, '0') + '1';
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
}