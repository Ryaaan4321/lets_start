#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        set<int> s1;
        set<int> s2;

        for(auto it:word){
            if(it>='a' && it<='z'){
                s1.insert(it-'a');
            }else{
                s2.insert(it-'A');
            }
        }
        int cnt=0;
        for(auto it:s1){
            if(s2.find(it)!=s2.end()){
                cnt++;
            }
        }
        return cnt;
    }
};