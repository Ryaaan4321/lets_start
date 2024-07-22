#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    string losingPlayer(int x, int y)
    {
        int totalValue = x * 75 + y * 10;

        // If total value is not a multiple of 115, the player who cannot play loses
        if (totalValue % 115 != 0)
        {
            return "Bob";
        }

        // Calculate the number of times 115 can be obtained
        int count115 = totalValue / 115;

        // If the count is even, Alice wins (because Bob will face the losing position)
        // If the count is odd, Bob wins (because Alice will face the losing position)
        if (count115 % 2 == 0)
        {
            return "Alice";
        }
        else
        {
            return "Bob";
        }
    }
};