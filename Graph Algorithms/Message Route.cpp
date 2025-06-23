// C++ 

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printPath(vector<int>& par, int node){
    vector<int> ans;
    while(node != -1){
        ans.push_back(node);
        node = par[node];
    }
    int n = ans.size();
    cout<<n<<endl;
    for(int i=n-1; i>=0; i--)   cout<<ans[i]<<" ";
}

void find(vector<vector<int>>& adj, int n){
    vector<int> par(n+1), vis(n+1);

    queue<int> qu;
    qu.push(1);

    vis[1] = 1;
    par[1] = -1;

    while(qu.size()){
        int node = qu.front();
        qu.pop();

        if(node == n){
            printPath(par, n);
            return;
        }

        for(auto& x: adj[node]){
            if(vis[x])  continue;

            qu.push(x);
            par[x] = node;
            vis[x] = 1;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find(adj, n);
    
    return 0;
}

// JAVA

public class Main{
  static void printPath(int [] par, int node){
        ArrayList<Integer> ans = new ArrayList<>();
        while(node != -1){
            ans.add(node);
            node = par[node];
        }
        int n = ans.size();
        System.out.println(n);
        for(int i=n-1; i>=0; i--)   System.out.print(ans.get(i)+" ");
    }

    static void find(ArrayList<Integer> adj [], int n){
        int par[] = new int[n+1], vis[] = new int[n+1];

        Queue<Integer> qu = new LinkedList<>();
        qu.offer(1);

        vis[1] = 1;
        par[1] = -1;

        while(!qu.isEmpty()){
            int node = qu.poll();

            if(node == n){
                printPath(par, n);
                return;
            }

            for(int x: adj[node]){
                if(vis[x] == 1)  continue;

                qu.offer(x);
                par[x] = node;
                vis[x] = 1;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
 
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        FastWriter so = new FastWriter();

        int n = sc.nextInt(), m = sc.nextInt();

        ArrayList<Integer> adj[] = new ArrayList[n+1];
        for(int i=0; i<=n; i++) adj[i] = new ArrayList<>();

        for(int i=0; i<m; i++){
            int u = sc.nextInt(), v = sc.nextInt();

            adj[u].add(v);
            adj[v].add(u);
        }

        find(adj, n);
 
        so.flush();
        so.close();
        sc.close();
    }
}
