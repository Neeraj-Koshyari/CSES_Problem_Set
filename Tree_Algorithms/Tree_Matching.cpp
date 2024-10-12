#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int find(int root, vector<vector<int>>& adj,int turn, int par, vector<vector<int>> &dp){
 
	if(dp[root][turn] != -1)	return dp[root][turn];
	int ans = 0;
 
	if(turn == 0){
		for(auto& x:adj[root]){
			if(x == par)	continue;
			ans += max(find(x,adj,0,root,dp), find(x,adj,1,root,dp));
		}
	}
	else{
		for(auto& x:adj[root]){
			if(x == par)	continue;
			ans = max(ans, 1 + find(root,adj,0,par,dp) - max(find(x,adj,0,root,dp),find(x,adj,1,root,dp)) + find(x,adj,0,root,dp));
		}
	}
 
	return dp[root][turn] = ans;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin>>n;
 
	vector<vector<int>> adj(n+1), dp(n+1, vector<int>(2,-1));
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
 
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	int val = find(1,adj,0,-1,dp);
	val = max(val,find(1,adj,1,-1,dp));
 
	cout<<val<<endl;
	
    return 0;
}
