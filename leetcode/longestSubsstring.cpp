#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;

using namespace std;
using str = std::string;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

class LongestSubstring
{
public:
    std::string longestPalindrome(str s)
    {
        if (s.length() <= 1)
        {
            return s;
        }
        /*and here taking two var maxlen and maxstr to keep a check of the maxstr and for that using two for loops
        if any moment j-i is greater than maxlen then updating it and checking if it is greater than the string that is stored in
        the maxstr if it is then updating the maxlen and maxstr thats it for this  algorithm bt this will end up taking O(n^3) time complexity which is so much
        and that endps up thinking to born a new method (●'◡'●)*/
        int maxlen = 1;
        string maxstr = s.substr(0, 1);
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i + maxlen; j <= s.length(); j++)
            {
                if (j - i > maxlen && isPalindrome(s.substr(i, j - i)))
                {
                    maxlen = j - i;
                    maxstr = s.substr(i, j - i);
                }
            }
        }
        return maxstr;
    }
    /*so what we are doing checking if the string is palindrome or not and we are doing it again and again and if we are doing
    again and again so that means dp and memoization*/

private:
    /*so here we are taking two pointers l and r and the dp state ;
    and now while taking two pointers there are some conditions can occur in which first is
    1- if(l>=r) then just simply return 1;
    2- if the state of the l and r =-1 or dp[l][r]=-1 then return dp[l][r]
    3- and the last case that can occur which is s[l]==s[r] then just return it;

    */
    bool solvewithdp(vector<vector<bool>> &dp, int i, int j, string &s)
    {
        if (i == j)
        {
            return dp[i][j] = true;
        }
        if (j - i == 1)
        {
            if (s[i] == s[j])
            {
                return dp[i][j] = true;
            }
            else
            {
                return dp[i][j] = false;
            }
        }
        if (s[i] == s[j] && dp[i + 1][j - 1] == true)
        {
            return dp[i][j] = true;
        }
        else
        {
            return dp[i][j] = false;
        }
    }

public:
    str longestPalindromedp(str s)
    {
        int n = s.size();
        int startIndex = 0;
        int maxlen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                solvewithdp(dp, i, j, s);
                if (dp[i][j] == true)
                {
                    if (j - i + 1 > maxlen)
                    {
                        startIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(startIndex, maxlen);
    }
    static bool isPalindrome(const str &s)
    {
        /*taking two pointers and placing one of them in the 0th index and one of them in the last index and checking if
        any moment they are not equal then it is not palindrome if they are equal then it will return true and it is a palindrome
        */
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;

        /*return s == string(s.rbegin(), s.rend());

        */
        /* this will also check for the string is palindrome or not bt we will go for another method*/
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    str s;
    getline(cin, s);

    LongestSubstring obj;
    str ans = obj.longestPalindromedp(s);

    cout << ans << endl;
}
