// c++

#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
void dfs(int node, vector<vector<int>>& adj, vector<int>& child){
	for(auto& x:adj[node]){
		dfs(x,adj,child);
		child[node] += child[x] + 1;
	}
	return;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin>>n;
 
	vector<vector<int>> adj(n+1);
	vector<int> child(n+1);
 
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
 
		adj[x].push_back(i);
	}
 
	dfs(1,adj,child);
 
	for(int i=1;i<=n;i++)	cout<<child[i]<<" ";
	cout<<endl;
 
    return 0;
}


// java
public class Main{
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        FastWriter so = new FastWriter();


        int n = sc.nextInt();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        int count[] = new int[n];

        for(int i=0; i<n; i++)  adj.add(new ArrayList<>());

        for(int i=1; i<n; i++){
            int x = sc.nextInt() - 1;
            adj.get(x).add(i);
        }

        Deque<Integer> dq = new ArrayDeque<>();
        Deque<Boolean> ready = new ArrayDeque<>();

        dq.addFirst(0);
        ready.addFirst(false);

        while(!dq.isEmpty()){
            int u = dq.removeFirst();
            boolean check = ready.removeFirst();

            if(!check){
                dq.addFirst(u);
                ready.addFirst(true);

                for(int x : adj.get(u)){
                    dq.addFirst(x);
                    ready.addFirst(false);
                }
            }
            else{
                for(int x : adj.get(u)){
                    count[u] += count[x]+1;
                }
            }
        }
        

        for(int x : count){
            so.print(x + " ");
        }
    }
}
