#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
class Solution
{
public:
    bool allElementsGreaterThan(vector<int> &nums, int value)
    {
        for (int num : nums)
        {
            if (num < value)
            {
                return false;
            }
        }
        return true;
    }

    int minOperations(vector<int> &nums, int k)
    {

        vector<int> ans;
        int cnt = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (auto  it : nums)
        {
            pq.push(it);
        }
        while (pq.size() && pq.top() < k)
        {
            long first = pq.top();
            pq.pop();
            long second = pq.top();
            pq.pop();
            pq.push(first * 2 + second);
            cnt++;
        }

        return cnt;
    }
};

int main()
{
    int k;
    int n;

    cin >> n;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution obj;
    int ans = obj.minOperations(a, k);

    cout << ans << endl;
    return 0;
}