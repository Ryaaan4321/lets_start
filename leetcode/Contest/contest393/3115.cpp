#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrime(int number)
    {
        if (number <= 1)
            return false;
        for (int i = 2; i * i <= number; ++i)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int mx = INT_MIN;
        while (j < nums.size())
        {
            if (isPrime(nums[i]) && isPrime(nums[j]))
            {
                mx = max(mx, j - i);
                j++;
            }
            else
            {
                if (!isPrime(nums[i]))
                    i++;
                if (!isPrime(nums[j]))
                    j++;
            }
        }
        return mx == INT_MIN ? -1 : mx;
    }
};