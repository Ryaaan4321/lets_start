#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        stack<string> st;
        int max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push("(");
                if (st.size() > max)
                {
                    max = st.size();
                }
            }
            else if (s[i] == ')')
            {
                st.pop();
            }
        }
        return max;
    }
};