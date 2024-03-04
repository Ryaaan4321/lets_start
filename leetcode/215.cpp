#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
/*And one day evrything got changed and he became his own companion;*/

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        /*so here to reduce the timecomplexity of this algorithm we are using the priprity queue and we are storing only the k elm on it
         and hence we know it will store the min element and then we will traverse in the array and check if the particular elm is bigger than
         that element if it is then push_back that element into the min_heap and in that algorithm we willl end up taking o(k) space complexity becuase
         we are storing only k elements in it and O(nlogk) so it is not much better becuase it is also taking the time complexity so what next aryan think about it
         */
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] > min_heap.top())
            {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        return min_heap.top();
    }

    int kthLargestElm(vector<int> &a, int k)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        return a[n - k];
        /*so it will be accepted bt the thing over here is it will take O(nlogk) time complexity to run  this
        code which will end up thinking to optimize this solution
        */
    }
};
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    Solution obj;
    int ans = obj.findKthLargest(a, k);
    cout << ans << endl;
}