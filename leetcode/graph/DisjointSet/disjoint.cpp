#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>

using namespace std;
class DisjointSet{
    public:
    vector<int>rank;
    vector<int>parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node=parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);

        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;
        }
    }

};
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findParent(2)==ds.findParent(4)){
        cout<<"same parent"<<endl;
    }else {
        cout<<" not same parent  "<<endl;
    }
}