#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // Finding the maximum element
        long long max = nums.back();
        nums.pop_back(); // Removing the last element
        ans += max;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp_k = k;
            while (temp_k--)
            {
                pq.push(nums[i] - 1);
                cout << pq.top() << "pq top" << endl;
                ans += pq.top();
                pq.pop();
            }
        }
        
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n); // Initialize vector after getting the size
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution obj;
    long long ans = obj.maximumHappinessSum(a, k);
    cout << ans << endl;
    return 0;
}
