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
