#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){	
	int n;
	cin>>n;
 
	ll mod = 1e9+7;
	vector<int> dp(n+1,0);
 
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		int x = 0;
		for(int j = 1;j<=6;j++){
			if(i>=j)	x = (x+dp[i-j])%mod;
		}
		dp[i] = x;
	}
	cout<<dp[n]<<endl;
	
	return 0;
}
