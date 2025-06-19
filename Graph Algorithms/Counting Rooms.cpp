// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
void dfs(int i, int j, vector<string>& v, int n, int m){
    if(i < 0 || j < 0 || i == n || j == m || v[i][j] == '#')    return;
    
    v[i][j] = '#';
 
    dfs(i+1, j, v, n, m);
    dfs(i, j+1, v, n, m);
    dfs(i-1, j, v, n, m);
    dfs(i, j-1, v, n, m);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m, count = 0;
    cin>>n>>m;
 
    vector<string> v(n);
    for(int i=0; i<n; i++)  cin>>v[i];
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == '.'){
                dfs(i, j, v, n , m);
                count++;
            }
        }
    }
 
    cout<<count<<endl;
    
    return 0;
}
