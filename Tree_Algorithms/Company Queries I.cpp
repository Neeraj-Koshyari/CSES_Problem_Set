// C++

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void binary_lifting (vector<vector<int>>& adj, vector<vector<int>>& lift, int node){
    for(auto& x: adj[node]){
        for(int bit = 1; bit<32; bit++){
            if(lift[x][bit-1] == -1)    break;
            lift[x][bit] = lift[lift[x][bit-1]][bit-1];
        }
        binary_lifting(adj, lift, x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    vector<vector<int>> adj(n+1), lift(n+1, vector<int>(32,-1));

    for(int i=2; i<=n; i++){
        int x;
        cin>>x;

        adj[x].push_back(i);
        lift[i][0] = x;
    }

    binary_lifting(adj, lift, 1);

    while(q--){
        int x, k;
        cin>>x>>k;

        for(int bit=31; bit>=0; bit--){
            if(((k>>bit) & 1))    x = lift[x][bit];
            if(x == -1) break;
        }
        cout<<x<<endl;
    }
    
    return 0;
}

// java
public Class Main{
  static void binary_lifting (ArrayList<Integer> adj[], int lift[][]){
        Queue<Integer> qu = new LinkedList<>();
        qu.offer(1);

        while(!qu.isEmpty()){
            int node = qu.poll();
            for(int x: adj[node]){
                for(int bit = 1; bit<32; bit++){
                    if(lift[x][bit-1] == -1)    break;
                    lift[x][bit] = lift[lift[x][bit-1]][bit-1];
                }
                qu.offer(x);
            }
        }
    }
 
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        FastWriter so = new FastWriter();

        int n = sc.nextInt(), q = sc.nextInt();

        ArrayList<Integer> adj[] = new ArrayList[n+1];
        int lift[][] = new int[n+1][32];

        for(int i=0; i<=n; i++) adj[i] = new ArrayList<>();
        for(int i=0; i<=n; i++){
            for(int j=0; j<32; j++) lift[i][j] = -1;
        }

        for(int i=2; i<=n; i++){
            int x = sc.nextInt();

            adj[x].add(i);
            lift[i][0] = x;
        }

        binary_lifting(adj, lift);

        while(q-- != 0){
            int x = sc.nextInt(), k = sc.nextInt();

            for(int bit=31; bit>=0; bit--){
                if(((k>>bit) & 1) == 1)    x = lift[x][bit];
                if(x == -1) break;
            }
            so.println(x);
        }
 
        so.flush();
        so.close();
        sc.close();
    }
}
