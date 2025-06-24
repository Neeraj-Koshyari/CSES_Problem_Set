// C++

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool find(int node, vector<vector<int>>& adj, vector<int>& group,int groupNumber){
    if(group[node] != -1)   return group[node] == groupNumber;

    group[node] = groupNumber;

    for(auto& x: adj[node]){
        if(!find(x, adj, group, 3 - groupNumber)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<int> group(n+1, -1);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(group[i] != -1)  continue;
        
        if(!find(i, adj, group, 1)){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    
    for(int i=1; i<=n; i++) cout<<group[i]<<" ";
    
    return 0;
}


// JAVA

public class Main{
  static boolean find(int node, ArrayList<Integer> [] adj, int [] group,int groupNumber){
        if(group[node] != 0)   return (group[node] == groupNumber);

        group[node] = groupNumber;

        for(int x: adj[node]){
            if(!find(x, adj, group, 3 - groupNumber)) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        FastWriter so = new FastWriter();

        int n = sc.nextInt(), m = sc.nextInt();

        ArrayList [] adj = new ArrayList[n+1];
        int group [] = new int[n+1];

        for(int i=0; i<=n; i++) adj[i] = new ArrayList<>();

        for(int i=0; i<m; i++){
            int u = sc.nextInt(), v = sc.nextInt();

            adj[u].add(v);
            adj[v].add(u);
        }

        int flag = 0;
        for(int i=1; i<=n; i++){
            if(group[i] != 0)  continue;
            
            if(!find(i, adj, group, 1)){
                flag = 1;
                break;
            }
        }

        if(flag == 1)   so.println("IMPOSSIBLE");
        else{
            for(int i=1; i<=n; i++) so.print(group[i]+" ");
        }
        
 
        so.flush();
        so.close();
        sc.close();
    }
}
