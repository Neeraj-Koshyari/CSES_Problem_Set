#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
	
	int n,sum,mod = 1e9+7;
	cin>>n>>sum;
 
	vector<int>v(n),dp(sum+1,0);
	for(int i=0;i<n;i++)	cin>>v[i];
 
	dp[0] = 1;
	for(int x = 1; x <= sum; x++){
		int val = 0;
		for(int i=0; i<n; i++){
			if(v[i] <= x) val = (val+dp[x-v[i]])%mod;
		}
		dp[x] = val;
	}
 
	cout<<dp[sum]<<endl;
 
	return 0;
}
