#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{

    int evalParanthesis(vector<string> &tokens)
    {
        stack<int> st;
        auto isValid = [](string tokens)
        {
            return (tokens == "+" || tokens == "-" || tokens == "*" || tokens == "/");
        };

        for (auto token : tokens)
        {
            if (isValid(token))
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if (token == "+")
                {
                    st.push(num1 + num2);
                }
                else if (token == "-")
                {
                    st.push(num1 - num2);
                }
                else if (token == "*")
                {
                    st.push(num1 * num2);
                }
                else
                {
                    st.push(num1 / num2);
                }
            }
            else
            {
                int num = stoi(token);
                st.push(num);
            }
        }
        return st.top();
    }
};

int32_t main(){
    int n;
    
}