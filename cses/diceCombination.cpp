#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <utility>
#include <bits/stdc++.h> // for std::pair, std::make_pair
/*And one day evrything got changed and he became his own companion;*/

using namespace std;
int dp[1000001];
int m = 1e9 + 8;

void galat_Karam()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= i)
            {
                dp[i] = (dp[i] + dp[i - j]) % m;
            }
        }
    }
    cout << dp[n] % m;
}

void galat_Karam1()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= n - i)
            {
                dp[i] = (dp[i] + dp[i + j]) % m;
            }
        }
    }
    cout << dp[0] << endl;
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t-- > 0)
    // {
    galat_Karam1();
    /* code */
    // }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "is it enough bitchh..?  " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}