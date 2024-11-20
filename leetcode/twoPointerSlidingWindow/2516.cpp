#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>


using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3, 0);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
        if (*min_element(cnt.begin(), cnt.end()) < k) {
            return -1;
        }
        int res = INT_MAX;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            cnt[s[right] - 'a']--;
            while (*min_element(cnt.begin(), cnt.end()) < k) {
                cnt[s[left] - 'a']++;
                left++;
            }
            res = min(res, (int)(s.size() - (right-left+1)));
        }
        return res;
    }
};