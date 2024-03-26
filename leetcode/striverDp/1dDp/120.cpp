#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int n;
    int m;
    int solve(int i, int j, vector<vector<int>> &nums, vector<vector<int>> dp)
    {
        if (i > n )
        {
            return 0;
        }
        if (i == n - 1 )
        {
            return nums[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = nums[i][j] + solve(i + 1, j, nums, dp);
        int diagonal = nums[i][j] + solve(i + 1, j + 1, nums, dp);

        return dp[i][j] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>> &nums)
    {
        n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, nums, dp);
    }
};
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;

    vector<vector<int>> comp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> comp[i][j];
        }
    }

    Solution obj;
    int ans = obj.minimumTotal(comp);
    cout << ans << endl;
}