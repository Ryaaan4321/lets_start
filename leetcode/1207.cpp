#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    /*And one day everything got changes and he became his own companion! */

    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        /*so we all know this problem is so easy becuase what we need to find is the freq of all the
        elements and if they are unique then return true and if not then false;
        and to store the freq of the element u can use anything u want either map or the vector also bt
        the thing is map stores the value in much better way so  iterating on the arrr and increasing the
        freq of the elm and then inserting all the freq into the set  and in the end checking if they are equal then
         thats great u know i know we both know thats its solved and thats great
         */
        unordered_set<int> set;
        for (int el : arr)
            freq[el]++;
        // for (auto [key, value] : freq)
        //     set.insert(value);

        for (auto &k : freq)
        {
            set.insert(k.second);
        }

        return set.size() == freq.size();
    }
};


int k = 1000;
bool uniqueOccurrences(vector<int> &arr)
{
    vector<int> freq(2 * k + 1);
    for (int el : arr)
        freq[el + k]++;
    sort(freq.begin(), freq.end());

    for (int i = 0; i < 2 * k; ++i)
    {
        if (freq[i] != 0 && freq[i] == freq[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution obj;
    bool ans = obj.uniqueOccurrences(a);
    cout << ans << "\n";
    return 0;
}
