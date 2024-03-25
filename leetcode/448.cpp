#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (!binary_search(nums.begin(), nums.end(), i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n); // Resize vector 'a' to size 'n'
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution obj;
    vector<int> ans = obj.findDisappearedNumbers(a);
    for (int i = 0; i < ans.size(); i++) // iterate over 'ans' instead of 'n'
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0; // add a return statement
}
