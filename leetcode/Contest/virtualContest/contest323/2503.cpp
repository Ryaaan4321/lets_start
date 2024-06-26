#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    // utna smjh ni aya abhi ar mehnat ki jarurat hai
    #define pii pair<int,int>
    #define F first;
    #define S second;
    struct Node{
        int row,col;
        int val;
        Node(int _r,int _c,int _v):row(_r),col(_c),val(_v){}
        bool operator < (const Node &rhs)const {
            if(val!=rhs.val)return val<rhs.val;
            if(row!=rhs.row)return row<rhs.row;
            return col<rhs.col;
        }
    };
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &que)
    {
        int n=grid.size();
        int m=grid[0].size();
        int q=que.size();
        vector<pii>que_and_idx;
        for(int i=0;i<q;i++){
            que_and_idx.push_back({que[i],i});
        }
        sort(que_and_idx.begin(),que_and_idx.end());
        vector<int>result(q);
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int tot_vis=0;
        set<Node>st;
        st.insert(Node(0,0,grid[0][0]));
        vis[0][0]=1;
        for(int i=0;i<q;i++){
            int mx_val=que_and_idx[i].first;
            int idx=que_and_idx[i].second;
            while(!st.empty() && st.begin()->val <mx_val){
                Node node=*st.begin();
                st.erase(st.begin());tot_vis++;
                vector<vector<int>>neighbours={{1,0},{0,1},{-1,0},{0,-1}};
                for(auto it:neighbours){
                    int r=node.row+it[0];
                    int c=node.col+it[1];
                    bool isvalid =(r>=0 && r<n) && (c>=0 && c<m);
                    if(!isvalid && !vis[r][c])continue;
                    vis[r][c]=1;
                    st.insert(Node(r,c,grid[r][c]));
                }

            }
            result[idx]=tot_vis;
        }
        return result;
    }
};

// ye wala smjh mein aya


// class Solution {
// public:
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         int m = grid.size(), n = grid[0].size(), k = queries.size();

//         vector<pair<int, int>>query(k); 
//         vector<int>ans(k);

//         for (int i = 0; i < k; i++) {
//             query[i] = {queries[i], i};
//         }
//         sort(query.begin(), query.end());

//         vector<vector<bool>>vis(m, vector<bool>(n, false));

//         //val of node, x, y
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>minh;

//         minh.push({grid[0][0], 0, 0});
//         vis[0][0] = true;
//         int cnt = 0;

//         for (auto &q : query) {
//             while (minh.size() > 0) {
//                 auto[val, i, j] = minh.top();
//                 if (val >= q.first) {
//                     break;
//                 }
//                 minh.pop();
//                 cnt++;
//                 if (i-1 >= 0 && vis[i-1][j] == false) 
//                     minh.push({grid[i-1][j], i-1, j}), vis[i-1][j] = true;
//                 if (j-1 >= 0 && vis[i][j-1] == false) 
//                     minh.push({grid[i][j-1], i, j-1}), vis[i][j-1] = true;
//                 if (i+1 < m && vis[i+1][j] == false) 
//                     minh.push({grid[i+1][j], i+1, j}), vis[i+1][j] = true;
//                 if (j+1 < n && vis[i][j+1] == false) 
//                     minh.push({grid[i][j+1], i, j+1}), vis[i][j+1] = true;
//             }
//             ans[q.second] = cnt;
//         }
//         return ans;
//     }
// };