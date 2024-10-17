#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
 
	int totalPage,mxPrice;
	cin>>totalPage>>mxPrice;
	vector<vector<int> > dp(totalPage+1, vector<int>(mxPrice+1,0));
 
	vector<int> price(totalPage),page(totalPage);
	for(int i=0;i<totalPage;i++)	cin>>price[i];
	for(int i=0;i<totalPage;i++)	cin>>page[i];
 
	for(int currPage = totalPage-1; currPage>=0; currPage--){
		for(int currPrice = 0; currPrice<=mxPrice; currPrice++){
			int totalPage = dp[currPage+1][currPrice];
 
			if(currPrice >= price[currPage])	totalPage = max(totalPage, page[currPage] + dp[currPage+1][currPrice-price[currPage]]);
 
			dp[currPage][currPrice] = totalPage;
		}
	}
 
	cout<<dp[0][mxPrice]<<endl;
 
	return 0;
}
