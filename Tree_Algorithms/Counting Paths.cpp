// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void binary_lifting(int node, vector<vector<int>>& adj, vector<vector<int>>& lift, vector<ll>& lvl, int par){
    for(auto& x: adj[node]){
        if(x == par)    continue;

        lvl[x] = lvl[node] + 1;
        lift[x][0] = node;

        for(int bit=1; bit<32; bit++){
            if(lift[x][bit-1] == -1) break;
            lift[x][bit] = lift[lift[x][bit-1]][bit-1];
        }

        binary_lifting(x, adj, lift, lvl, node);
    }
}

void dfs(int node, int par, vector<vector<int>>& adj, vector<ll>& ans){
    for(auto& x: adj[node]){
        if(x == par)    continue;

        dfs(x, node, adj, ans);
        ans[node] += ans[x];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1), lift(n+1, vector<int>(32,-1));
    vector<ll> lvl(n+1), ans(n+1);

    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    binary_lifting(1, adj, lift, lvl, -1);

    while(m--){
        int u,v;
        cin>>u>>v;

        ans[u] += 1;
        ans[v] += 1;

        if(lvl[u] > lvl[v]) swap(u,v);

        int diff = lvl[v] - lvl[u];
        for(int bit = 31; bit>=0; bit--){
            if((diff>>bit)&1)   v = lift[v][bit];
        }

        if(u == v){
            ans[u] -= 1;
            if(lift[u][0] != -1)    ans[lift[u][0]] -= 1;
            continue;
        }

        for(int bit = 31; bit>=0; bit--){
            if(lift[u][bit] != lift[v][bit]){
                u = lift[u][bit];
                v = lift[v][bit];
            }
        }

        u = lift[u][0];
        ans[u] -= 1;
        if(lift[u][0] != -1)    ans[lift[u][0]] -= 1;
    }

    dfs(1, -1, adj, ans);

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    
    return 0;
}
