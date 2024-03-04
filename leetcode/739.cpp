#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    static vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        static stack<pair<int, int>> st;

        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && temperatures[i] > st.top().first)
            {
                int stacktemp = st.top().first;
                int stackInd = st.top().second;
                st.pop();
                res[stackInd] = i - stackInd;
            }
            st.push({temperatures[i], i});
        }
        return res;
    }

private:
    static vector<int> dailyTemperatures2(vector<int> &tempratures)
    {
        int n = tempratures.size();
        vector<int> res(n, 0);
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (tempratures[j] > tempratures[i])
                {
                }
            }
        }
    }
};

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    Solution obj;
    vector<int> ans = obj.dailyTemperatures(a);

    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
