#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Recursion + DP
int find(int n, int m,vector<vector<int> >& dp){
	if(n == m)	return 0;
	if(n == 1)	return m-1;
	if(m == 1)	return n-1;
 
	if(dp[n][m] != -1)	return dp[n][m];
 
	int val = 1e9;
	//vertical cuts
	for(int i=1;i<m;i++){
		int x = 1 + find(n,i,dp) + find(n,m-i,dp);
		val = min(val,x);
	}
 
	//horizontal cuts
	for(int i=1;i<n;i++){
		int x = 1 + find(i,m,dp) + find(n-i,m,dp);
		val = min(val,x);
	}
	return dp[n][m] = val;
}



int main(){
    int n,m;
	cin>>n>>m;


  // Tabular method
	vector<vector<int> > dp(n+1, vector<int>(m+1,0));
	for(int i=2;i<=n;i++)	dp[i][1] = i-1;
	for(int i=2;i<=m;i++)	dp[1][i] = i-1;
 
	for(int i = 2; i<=n; i++){
		for(int j = 2; j<=m; j++){
			if(i == j){
				dp[i][j] = 0;
				continue;
			}
 
			int val = 1e9;
			//vertical cuts
			for(int k=1;k<j;k++){
				int x = 1 + dp[i][k] + dp[i][j-k];
				val = min(val,x);
			}
 
			//horizontal cuts
			for(int k=1;k<i;k++){
				int x = 1 + dp[k][j] + dp[i-k][j];
				val = min(val,x);
			}
			dp[i][j] = val;
		}
	}
	cout<<dp[n][m]<<endl;
 
	return 0;
}
