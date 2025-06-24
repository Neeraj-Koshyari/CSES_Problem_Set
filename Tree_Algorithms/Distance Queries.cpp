// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void binary_lifting(vector<vector<int>>& adj, vector<vector<int>>& lift, vector<int>& lvl, int LOG, int node, int par){
    for(auto& x: adj[node]){
        if(x == par)    continue;

        lift[x][0] = node;
        for(int bit = 1; bit<LOG; bit++){
            if(lift[x][bit-1] == -1)    break;
            lift[x][bit] = lift[lift[x][bit-1]][bit-1];
        }

        lvl[x] = lvl[node]+1;
        binary_lifting(adj, lift, lvl, LOG, x, node);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,q, LOG = 1;
    cin>>n>>q;

    while((1ll<<LOG) <= n)  LOG++;

    vector<vector<int>> adj(n+1), lift(n+1, vector<int>(LOG, -1));
    vector<int> lvl(n+1);

    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    binary_lifting(adj, lift, lvl, LOG, 1, -1);

    int ans = 0;
    while(q--){
        int u, v;
        cin>>u>>v;

        if(lvl[u] > lvl[v]) swap(u,v);

        int diff = (lvl[v] - lvl[u]);
        ans = diff;

        for(int bit = LOG-1; bit>=0; bit--){
            if((diff >> bit) & 1)   v = lift[v][bit];
        }

        if(v == u){
            cout<<ans<<endl;
            continue;
        }

        for(int bit = LOG-1; bit>=0; bit--){
            if(lift[u][bit] != lift[v][bit]){
                u = lift[u][bit];
                v = lift[v][bit];

                ans += 2*(1<<bit);
            }
        }
        ans += 2;
        cout<<ans<<endl;
    }


    
    return 0;
}
