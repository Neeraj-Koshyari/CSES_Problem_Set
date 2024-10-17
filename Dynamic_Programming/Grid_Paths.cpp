#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int GridPath(int i, int j, vector<string>& v, vector<vector<int> >& dp,int mod){
	if(i == v.size()-1 && j == v[0].size()-1)	return 1;
	if(i>=v.size() || j>=v[0].size() || v[i][j] == '*')	return 0;
 
	if(dp[i][j] != -1)	return dp[i][j];
 
	int right = GridPath(i,j+1,v,dp,mod);
	int down = GridPath(i+1,j,v,dp,mod);
	return dp[i][j] = (right+down)%mod;
}
 
int main(){
	
	int n,mod=1e9+7;
	cin>>n;
 
	vector<string> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
 
	vector<vector<int> > dp(n,vector<int>(n,-1));
	if(v[n-1][n-1] == '*' || v[0][0] == '*')	cout<<0<<endl;
	else	cout<<GridPath(0,0,v,dp,mod)<<endl;
 
	return 0;
}
