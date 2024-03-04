#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool check(vector<int> &counter)
    {
        for (int &it : counter)
        {
            if (it != 0)
                return false;
        }
        return true;
    }

     int search(string pat, string text)
    {
        int n = text.size();
        vector<int> counter(26, 0);
        for (int i = 0; i < pat.length(); i++)
        {
            char ch = pat[i];
            counter[ch - 'a']++;
        }
        /*pehla kam ye tha ki hme pattern wale numbers ki map mein frequency store kar leni thee*/
        /*then  sliding window k  formula uthaya ar jis bhi element mein us text ke uski frequency ghata di
        agr woh sab 0 hai to matlb who hmare pattern k hi numbers hai jo match kar rhe hai*/

        int i = 0;
        int j = 0;
        int k = pat.size();
        int ans = 0;

        while (j < n)
        {
            counter[text[j] - 'a']--;

            if (j - i + 1 == k)
            {
                if (check(counter))
                {
                    ans++;
                }
                counter[text[i] - 'a']++;
                i++;
            }
            j++;

            /* code */
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

    Solution obj;
    int ans = obj.search(s, t);

    cout << ans << endl;
    return 0;
}