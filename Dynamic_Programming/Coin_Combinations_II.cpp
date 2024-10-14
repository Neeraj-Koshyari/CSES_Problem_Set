#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){

	int n,sum,mod=1e9+7;
	cin>>n>>sum;
 
	vector<int> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
 
	vector<vector<int> > dp(n+1,vector<int>(sum+1,0));
	for(int i=0;i<n;i++)	dp[i][0] = 1ll;
 
	for(int i=n-1; i>=0; i--){
		for(int s = 1; s<=sum; s++){
			int val = dp[i+1][s]%mod;
			if(v[i] <= s)	val = (val + dp[i][s-v[i]])%mod;
			dp[i][s] = val%mod;
		}
	}
 
	cout<<dp[0][sum]%mod<<endl;
 
	return 0;
}
