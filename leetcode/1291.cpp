#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        string ans = "123456789";
        vector<int> a;

        for (int len = 2; len <= ans.size(); len++)
        {
            for (int startIdx = 0; startIdx <= ans.size() - len; startIdx++)
            {
                string temp = ans.substr(startIdx, len);
                int poss = stoi(temp);

                if (poss >= low && poss <= high)
                {
                    a.push_back(poss);
                }
            }
        }
        return a;
    }
};
int main()
{
    int low;
    int high;
    cin >> low;
    cin >> high;

    Solution obj;
    vector<int> ans = obj.sequentialDigits(low, high);
    for (int num : ans)
    {
        cout << num<<" ";
    }
}
