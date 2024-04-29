#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool isvalid(int i, int j, int n, int m)
    {
        return (i >= 0) && (i < n) && (j >= 0) && (j < m);
    }
    bool boundarycheck(int i, int j, int n, int m)
    {
        return (i != 0) && (i != n) && (j != 0) && (j != m);
    }

    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid)
    {
        if (min(i, j) < 0 || i >= n || j >= m || grid[i][j] != 'O')
        {
            return;
        }
        grid[i][j] = 'P';
        dfs(i - 1, j, n, m, grid);
        dfs(i + 1, j, n, m, grid);
        dfs(i, j + 1, n, m, grid);
        dfs(i, j - 1, n, m, grid);
    }
    void solve(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int j = 0; j < m; j++)
        {
            dfs(0, j, n, m, grid);
            dfs(n - 1, j, n, m, grid);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(i, 0, n, m, grid);
            dfs(i, m - 1, n, m, grid);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'O')
                {
                    grid[i][j] = 'X';
                }
                if (grid[i][j] == 'P')
                {
                    grid[i][j] = 'O';
                }
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        const int r = board.size();
        const int c = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // top border
        for (int i = 0; i < c; ++i)
        {
            if (board[0][i] == 'X' || board[0][i] == 'N')
            {
                continue;
            }
            else
            {
                q.push(make_pair(0, i));
                while (q.size())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if (x < 0 || x >= r || y < 0 || y >= c ||
                        board[x][y] == 'X' || board[x][y] == 'N')
                    {
                        continue;
                    }
                    board[x][y] = 'N';
                    for (int d = 0; d < dir.size(); ++d)
                    {
                        q.push(make_pair(x + dir[d][0], y + dir[d][1]));
                    }
                }
            }
        }

        // right border
        for (int i = 0; i < r; ++i)
        {
            if (board[i][c - 1] == 'X' || board[i][c - 1] == 'N')
            {
                continue;
            }
            else
            {
                q.push(make_pair(i, c - 1));
                while (q.size())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if (x < 0 || x >= r || y < 0 || y >= c ||
                        board[x][y] == 'X' || board[x][y] == 'N')
                    {
                        continue;
                    }
                    board[x][y] = 'N';
                    for (int d = 0; d < dir.size(); ++d)
                    {
                        q.push(make_pair(x + dir[d][0], y + dir[d][1]));
                    }
                }
            }
        }
        // bottom border
        for (int i = 0; i < c; ++i)
        {
            if (board[r - 1][i] == 'X' || board[r - 1][i] == 'N')
            {
                continue;
            }
            else
            {
                q.push(make_pair(r - 1, i));
                while (q.size())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if (x < 0 || x >= r || y < 0 || y >= c ||
                        board[x][y] == 'X' || board[x][y] == 'N')
                    {
                        continue;
                    }
                    board[x][y] = 'N';
                    for (int d = 0; d < dir.size(); ++d)
                    {
                        q.push(make_pair(x + dir[d][0], y + dir[d][1]));
                    }
                }
            }
        }

        // left border
        for (int i = 0; i < r; ++i)
        {
            if (board[i][0] == 'X' || board[i][0] == 'N')
            {
                continue;
            }
            else
            {
                q.push(make_pair(i, 0));
                while (q.size())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if (x < 0 || x >= r || y < 0 || y >= c ||
                        board[x][y] == 'X' || board[x][y] == 'N')
                    {
                        continue;
                    }
                    board[x][y] = 'N';
                    for (int d = 0; d < dir.size(); ++d)
                    {
                        q.push(make_pair(x + dir[d][0], y + dir[d][1]));
                    }
                }
            }
        }

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (board[i][j] == 'N')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};