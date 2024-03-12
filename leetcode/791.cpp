#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        int count[26] = {0};
        for (char &ch : s)
        {
            count[ch - 'a']++;
        }
        string result = "";
        for (char &ch : order)
        {
            while (count[ch - 'a'] > 0)
            {
                result.push_back(ch);
                count[ch - 'a']--;
            }
        }
        for (char &ch : s)
        {
            if (count[ch - 'a'] > 0)
            {
                result.push_back(ch);
            }
        }
        return result;
    }
    string customSortString(string order, string s)
    {
        vector<int> index(26, -1);//to store the index of all the characters;
        auto myComparator = [&index](char &ch1, char &ch2)
        {
            return index[ch1-'a'] > index[ch2-'a'];
            //lambda to check which char is bigger or smmaler
        };

        for(int i=0;i<order.length();i++)
        {
            char ch=order[i];//char =order[i];
            index[ch-'a']=i;
            //and storing that in the index ;
        } 
        sort(begin(s),end(s),myComparator);

        return s;
        
    
    }
};