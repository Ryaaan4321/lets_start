#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class SmallestInfiniteSet
{
public:
    vector<int> a;
    SmallestInfiniteSet()
    {
        const int n = 1000;
        for (int i = 1; i <= n; i++)
        {
            a.push_back(i);
        }
    }

    int popSmallest()
    {
        sort(a.begin(), a.end());
        int pop_value = a[0];
        a.erase(a.begin() + 0);
        return pop_value;
    }

    void addBack(int num)
    {
        if (count(a.begin(), a.end(), 0)==num)
        {
            a.push_back(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */