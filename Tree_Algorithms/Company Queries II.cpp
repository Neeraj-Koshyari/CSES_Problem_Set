// c++

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void binary_lifting(vector<vector<int>>& adj, vector<vector<int>>& lift, int node, vector<int>& level){
    for(auto& x: adj[node]){
        for(int bit=1; bit<32; bit++){
            if(lift[x][bit-1] == -1)    break;
            lift[x][bit] = lift[lift[x][bit-1]][bit-1];
        }
        level[x] = level[node] + 1;
        binary_lifting(adj, lift, x, level);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,q;
    cin>>n>>q;

    vector<vector<int>> adj(n+1), lift(n+1, vector<int>(32, -1));
    vector<int> level(n+1);
    level[1] = 0;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;

        adj[x].push_back(i);
        lift[i][0] = x;
    }

    binary_lifting(adj, lift, 1, level);
    
    while(q--){
        int u, v;
        cin>>u>>v;

        if(level[u] < level[v]) swap(u,v);

        int diff = level[u] - level[v];
        for(int bit = 31; bit>=0; bit--){
            if((diff>>bit) & 1) u = lift[u][bit];
            if(u == -1) break;
        }

        if(u == v){
            cout<<u<<endl;
            continue;
        }

        for(int bit = 31; bit>=0; bit--){
            if(lift[u][bit] != lift[v][bit]){
                u = lift[u][bit];
                v = lift[v][bit];
            }
        }
        cout<<lift[u][0]<<endl;
    }

    
    return 0;
}

// JAVA
public class Main{
  public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        FastWriter so = new FastWriter();

        int n = sc.nextInt(), q = sc.nextInt();
        ArrayList<Integer> adj[] = new ArrayList[n+1];
        for(int i=0; i<=n; i++) adj[i] = new ArrayList<>();

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        int level[] = new int[n+1];
        int lift[][] = new int[n+1][LOG];
        level[1] = 1;

        for(int i=2; i<=n; i++){
            int x = sc.nextInt();

            adj[x].add(i);
            lift[i][0] = x;
            level[i] = level[x] + 1;
        }

        for(int bit = 1; bit < LOG; bit++){
            for(int v = 1; v <= n; v++){
                int prev = lift[v][bit-1];
                if(prev != 0)
                    lift[v][bit] = lift[prev][bit-1];
            }
        }


        while(q-- != 0){
            int u = sc.nextInt(), v = sc.nextInt();

            if(level[u] < level[v]){
                int temp = u;
                u = v;
                v = temp;
            }

            int diff = level[u] - level[v];
            for(int bit = LOG-1; bit>=0; bit--){
                if(((diff>>bit) & 1) == 1)  u = lift[u][bit];
            }

            if(u == v){
                so.println(u);
                continue;
            }

            for(int bit = LOG-1; bit >=0; bit--){
                if(lift[u][bit] != lift[v][bit]){
                    u = lift[u][bit];
                    v = lift[v][bit];
                }
            }
            so.println(lift[u][0]);
        }
 
        so.flush();
        so.close();
        sc.close();
    }
}
