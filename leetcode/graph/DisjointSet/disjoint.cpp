#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;
/*
why does the complexity of the disjoint sset is constant

https://hideoushumpbackfreak.com/algorithms/data-struct-union-find#-asymptotic-complexity
https://stackoverflow.com/questions/6342967/why-is-the-ackermann-function-related-to-the-amortized-complexity-of-union-find
https://tarunjain07.medium.com/union-find-disjoint-set-union-dsu-notes-24f3e228858d

*/
class DisjointSet
{
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> sz;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sz.resize(n + 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int findParent(int node)
    {
        if (node = parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u==ulp_v)return;
        if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else if (rank[ulp_v] > rank[ulp_u])
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }
    }
    void unionbysize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u==ulp_v)return;
        if (sz[ulp_u] > sz[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else if (sz[ulp_v] > sz[ulp_u])
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            sz[ulp_u] += sz[ulp_v];
        }
    }
};
int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findParent(2) == ds.findParent(4))
    {
        cout << "same parent" << endl;
    }
    else
    {
        cout << " not same parent  " << endl;
    }
}