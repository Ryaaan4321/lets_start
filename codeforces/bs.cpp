#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
// And one day evrything got changed and he became his own companion;
using namespace std;
#define ll long long
#define int long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vi> vvi;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    vi a(n);
    vi aa(k);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> aa[i];
    }

    for (int i = 0; i < k; i++)
    {
        int left = 0;
        int right = n - 1;
        bool found = false;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (a[mid] == aa[i])
            {
                found = true;
                break;
            }
            else if (a[mid] < aa[i])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

