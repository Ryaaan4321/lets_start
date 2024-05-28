#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

/*you gotta be almost insane to your craft - mc gregor*/
class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int> &a, vector<int> &q, int x)
    {
        map<int, int> mp;
        for (int i = 0; i < a.size(); i++)
        {
            mp.insert(i, a[i]);
        }
        vector<int> ans;
        for (int i = 0; i < q.size(); i++)
        {
            if (mp.find(x) != mp.end())
            {
                for (auto it : mp)
                {
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};