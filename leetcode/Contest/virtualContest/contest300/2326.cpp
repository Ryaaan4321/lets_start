#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*similar problems to understand this concept more in ease are : leetcode 59,leetcode 54*/

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        int top = 0;
        int left = 0;
        int right = n - 1;
        int down = m - 1;
        int dir = 0;

        vector<vector<int>> answer(m, vector<int>(n, -1));
        while (top <= down && left <= right)
        {
            if (dir == 0)
            {
                for (int i = top; i <= right; i++)
                {
                    if (!head)
                    {
                        return answer;
                    }
                    int val = head->val;
                    answer[top][i] = val;
                    head = head->next;
                }
                top++;
            }
            if (dir == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    if (!head)
                    {
                        return answer;
                    }
                    int val = head->val;
                    answer[i][right] = val;
                    head = head->next;
                }
                right--;
            }
            if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    if (!head)
                    {
                        return answer;
                    }
                    int val = head->val;
                    answer[down][i] = val;
                    head = head->next;
                }
                down--;
            }
            if (dir == 3)
            {
                for (int i = down; i >= top; i--)
                {
                    if (!head)
                    {
                        return answer;
                    }
                    int val = head->val;
                    answer[i][left] = val;
                    head = head->next;
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return answer;
    }
};