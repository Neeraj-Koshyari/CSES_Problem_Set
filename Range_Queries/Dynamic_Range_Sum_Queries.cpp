#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
void build(int idx, int l, int r, vector<ll>& v, vector<ll>& seg){
	if(l == r){
		seg[idx] = v[l];
		return;
	}
 
	int mid = (l+r)/2;
	build(2*idx+1, l, mid, v, seg);
	build(2*idx+2, mid+1, r, v, seg);
 
	seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}
 
ll query(int idx, int l, int r, int ql, int qr, vector<ll>& seg){
	if(l>=ql && r<=qr)	return seg[idx];
	if(r<ql || l>qr)	return 0;
 
	int mid = (l+r)/2;
	ll left = query(2*idx+1,l,mid,ql,qr,seg);
	ll right = query(2*idx+2,mid+1,r,ql,qr,seg);
 
	return left + right;
}
 
void update(int idx, int l, int r, int k, int u,vector<ll>& seg){
	if(l == r){	
		seg[idx] = u;
		return;
	}
 
	int mid = (l+r)/2;
	if(k<=mid)	update(2*idx+1, l, mid, k, u, seg);
	else update(2*idx+2,mid+1, r, k, u, seg);
 
	seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n,q;
	cin>>n>>q;
 
	vector<ll> v(n), seg(4*n);
	for(int i=0;i<n;i++)	cin>>v[i];
 
	build(0,0,n-1,v,seg);
 
	while(q--){
		int type,x,y;
		cin>>type>>x>>y;
 
		if(type == 1)	update(0,0,n-1,x-1,y,seg);
		else	cout<<query(0,0,n-1,x-1,y-1,seg)<<endl;
	}
	return 0;
}
