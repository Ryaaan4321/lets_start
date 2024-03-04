#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mpp;
        for (char c : s)
        {
            mpp[c]++;
        }
        vector<char> sortedChar;
        for (const auto &entry : mpp)
        {
            sortedChar.push_back(entry.first);
        }
        sort(sortedChar.begin(), sortedChar.end(), [&](char a, char b)
             { return mpp[a] > mpp[b]; });
        string result;
        for (char c : sortedChar)
        {
            result += string(mpp[c], c);
        }
        return result;
    }

    /*public:
      string frequencySort(string s) {
          unordered_map<char, int> freq;
          for (auto ch : s) {
              freq[ch]++;
          }
          vector<pair<char, int>> freqArr;
          for (auto& [ch,fq] : freq) {
              freqArr.push_back({ch,fq});
          }
          auto cmp = [&](const pair<char, int>& a, const pair<char, int>& b) {
              return a.second > b.second;
          };
          sort(freqArr.begin(), freqArr.end(), cmp);
          string ans = "";
          for (auto& [ch,fq] : freqArr) {
              ans.append({ch,fq});
          }
          return ans;

      }
      */
/*public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (auto ch : s)
        {
            freq[ch]++;
        }

        vector<vector<char>> bucketData(s.length() + 1);
        for (auto [fq, ch] : freq)
            bucketData[fq].push_back(ch);
        string ans = "";
        for (int fq = s.length(); fq >= 1; fq--)
        {
            for (auto ch : bucketData[fq])
            {
                ans.append(fq.ch);
            }
        }
    }
    */
};
int32_t main()
{
    Solution obj;
    string s;
    cin >> s;
    string ans = obj.frequencySort(s);
    cout << ans << endl;
    return 0;
}