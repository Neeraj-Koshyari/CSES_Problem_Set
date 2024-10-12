#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){	
	int n,x;
	cin>>n>>x;
 
	vector<int> v(n),dp(x+1,0);
	for(int i=0;i<n;i++)	cin>>v[i];
 
	for(int i = 1; i<=x; i++){
		int val = 1e8;
		for(int j = 0; j<n; j++){
			if(i >= v[j])	val = min(val, dp[i-v[j]]);
		}
		dp[i] = val + 1;
	}
 
	if(dp[x] >= 1e8) cout<<-1<<endl;
	else cout<<dp[x]<<endl;
 
	return 0;
}
