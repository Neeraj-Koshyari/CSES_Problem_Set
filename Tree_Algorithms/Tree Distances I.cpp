// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
void dfs1(vector<vector<int>>& adj, int node, int par, vector<int>& inDis){
    for(auto& x: adj[node]){
        if(x == par)    continue;
        dfs1(adj, x, node, inDis);
        inDis[node] = max(inDis[node], 1 + inDis[x]);
    }
}
 
void dfs2(vector<vector<int>>& adj, int node, int par, vector<int>& inDis, vector<int>& outDis){
    int mx1 = -1, mx2 = -1;
    for(auto& x: adj[node]){
        if(x == par)    continue;
 
        if(mx1 <= inDis[x]){
            mx2 = mx1;
            mx1 = inDis[x];
        }
        else if(mx2 < inDis[x]) mx2 = inDis[x];
    }
 
    for(auto& x: adj[node]){
        if(x == par)    continue;
 
        int val = mx1;
        if(val == inDis[x]) val = mx2;
 
        outDis[x] = 1 + max(outDis[node], 1 + val);
 
        dfs2(adj, x, node, inDis, outDis);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
 
    vector<vector<int>> adj(n);
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
 
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
 
    vector<int> inDis(n), outDis(n);
    
    dfs1(adj, 0, -1, inDis);
    dfs2(adj, 0, -1, inDis, outDis);
 
    for(int i=0; i<n; i++)  cout<<max(inDis[i], outDis[i])<<" ";
    
    return 0;
}
