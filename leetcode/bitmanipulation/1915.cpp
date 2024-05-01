#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

/*a brief explantion of the algorithm - https://miro.com/app/board/uXjVKNOgrlA=/*/

class Solution
{
public:
     typedef long long ll;
    long long wonderfulSubstrings(string word)
    {
        ll result=0;
        unordered_map<ll ,ll>mp;
        mp[0]=1;
        int curr_xorr=0;
        for(char &ch:word){
            int shift=ch-'a';
            curr_xorr^=(1<<shift);
            result+=mp[curr_xorr];
            for(char ch1='a';ch1<='j';ch1++){
                shift=ch1-'a';
                ll odd_xorr=(curr_xorr^(1<<shift));
                result+=mp[odd_xorr];
            }
            mp[curr_xorr]++;
        }
        return result;
    }
};