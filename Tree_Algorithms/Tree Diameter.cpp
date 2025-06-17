// C++

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

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

    queue<int> qu;
    qu.push(0);

    int last_node = 0;
    vector<int> vis(n);
    
    while(qu.size()){
        last_node = qu.front();
        qu.pop();

        vis[last_node] = 1;
        for(auto& x: adj[last_node]){
            if(vis[x])  continue;
            qu.push(x);
        }
    }

    qu.push(last_node);
    int level = -1;

    vis = vector<int>(n,0);

    while(qu.size()){
        int sz = qu.size();
        level++;
        while(sz--){
            int node = qu.front();
            qu.pop();

            vis[node] = 1;
            for(auto& x: adj[node]){
                if(vis[x])  continue;
                qu.push(x);
            }
        }
    }

    cout<<level<<endl;
    
    return 0;
}

// JAVA
public class Main{
  public static void main(String[] args) throws IOException {
        // FastReader sc = new FastReader();
        // FastWriter so = new FastWriter();

        Scanner sc = new Scanner(System.in)
        
        int n = sc.nextInt();
        ArrayList<Integer> adj[] = new ArrayList[n+1];
        for(int i=0; i<=n; i++)  adj[i] = new ArrayList<>();

        for(int i=1; i<n; i++){
            int u = sc.nextInt(), v = sc.nextInt();

            adj[u].add(v);
            adj[v].add(u);
        }

        Queue<Integer> qu = new LinkedList<>();
        qu.offer(1);

        int last_node = 0;
        int vis[] = new int[n+1];

        while(!qu.isEmpty()){
            last_node = qu.poll();

            vis[last_node] = 1;
            for(int x : adj[last_node]){
                if(vis[x] == 1) continue;
                qu.offer(x);
            }
        }

        qu.offer(last_node);
        int level = -1;
        vis = new int[n+1];

        while(!qu.isEmpty()){
            int sz = qu.size();
            level++;

            while(sz-- != 0){
                last_node = qu.poll();

                vis[last_node] = 1;
                for(int x : adj[last_node]){
                    if(vis[x] == 1) continue;
                    qu.offer(x);
                }
            }
        }

        System.out.println(level);
    }
}
