#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
	
	int n,cnt=0;
	cin>>n;
 
	while(n){
		int val = n, mx = 0;
		while(val){
			mx = max(mx,val%10);
			val/=10;
		}
		n -= mx;
		cnt++;
	}
	cout<<cnt<<endl;
 
	return 0;
}
