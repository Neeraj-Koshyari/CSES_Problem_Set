// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
void dfs1(int node, int par, vector<vector<int>>& adj, vector<ll>& dis, vector<ll>& count){
    for(auto& x: adj[node]){
        if(x == par)    continue;
 
        dfs1(x, node, adj, dis, count);
 
        dis[node] += dis[x] + count[x];
        count[node] += count[x];
    }
    count[node]++;
}
 
void dfs2(int node, int par, vector<vector<int>>& adj, vector<ll>& dis, vector<ll>& count){
    for(auto& x: adj[node]){
        if(x == par)   continue;
 
        dis[x] = dis[x] + (dis[node] - (dis[x] + count[x]) + (adj.size() - count[x]));
        dfs2(x, node, adj, dis, count);
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
 
    vector<ll> dis(n), count(n);
    dfs1(0, -1, adj, dis, count);
    dfs2(0, -1, adj, dis, count);
 
    for(int i=0; i<n; i++)  cout<<dis[i]<<" ";
    
    return 0;
}
