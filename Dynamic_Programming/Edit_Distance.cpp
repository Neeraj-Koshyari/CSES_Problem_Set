#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
    string a,b;
    cin>>a>>b;
    int n = a.length(), m = b.length();\
    
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
 
	for(int i=0;i<=m;i++)	dp[n][i] = m-i;
	for(int i=0;i<=n;i++)	dp[i][m] = n-i;
 
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			int val;
			if(a[i] != b[j]){
				int x = 1 + dp[i+1][j+1];        // replace
				int y = 1 + dp[i][j+1];          // add
				int z = 1 + dp[i+1][j];        // remove
				val = min(x,min(y,z));
			}
			else val = dp[i+1][j+1];
			
			dp[i][j] = val;
		}
	}
    cout<<dp[0][0]<<endl;
 
	return 0;
}
