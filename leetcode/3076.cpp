#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> shortestSubstrings(vector<string> &arr)
    {
        unordered_map<int, unordered_set<string>> mpp;
        int n = arr.size();
        vector<string> ans(n, "");
        for (int k = 0; k < n; k++)
        {
            string s = arr[k];
            int sz = s.size();
            for (int i = 0; i < sz; i++)
            {
                for (int j = i; j < sz; j++)
                {
                    string temp = s.substr(i, j - i + 1);
                    mpp[k].insert(temp);
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            string min_string = "";
            string s = arr[k];
            int min_length = INT_MAX;
            int sz = s.size();

            for (auto temp : mpp[k])
            {
                bool flag = false;
                for (int j = 0; j < n; j++)
                {
                    if (k == j)
                        continue;
                    if (mpp[j].find(temp) != mpp[j].end())
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    if(temp.length()<min_length){
                        min_length=temp.length();
                        min_string=temp;
                    }
                    else if(temp.length()==min_length && temp<min_string){
                        min_string=temp;
                    }
                }
            }
            ans[k]=min_string;

        }
        return ans;
    }
};
