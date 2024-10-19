#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
 
	int n,m,mod=1e9+7;
	cin>>n>>m;
	vector<int> v(n);
	vector<vector<int> > dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<n;i++)	cin>>v[i];
 
	for(int i=1;i<=m;i++)	dp[n][i] = 1;
 
	for(int i=n-1;i>=0;i--){
		for(int last = 1; last<=m; last++){
			int ans = 0;
			if(v[i] == 0){
				for(int curr = -1; curr <= 1; curr++){
					v[i] = last + curr;
					if(v[i]>=1 && v[i]<=m) ans = (ans  + dp[i+1][v[i]])%mod;
					v[i] = 0;
				}
			}
			else{
				if(abs(v[i] - last) > 1)	ans = 0;
				else ans = dp[i+1][v[i]];
			}
			dp[i][last] = ans;
		}
	}
 
	int ans = 0;
	if(v[0] == 0){
		for(int i=1;i<=m;i++){
			ans = (ans + dp[1][i])%mod;
		}
	}
	else	ans = dp[1][v[0]];
	cout<<ans<<endl;
	return 0;
}
