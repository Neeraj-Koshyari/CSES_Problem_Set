// C++ 

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int find(int x, vector<ll>& par){
    if(x == par[x]) return x;
    return par[x] = find(par[x], par);
}

void join(int u, int v, vector<ll>& par, vector<ll>& count){
    int pu = find(u, par), pv = find(v, par);

    if(par[pu] == par[pv])  return;

    if(count[pu] < count[pv])   swap(pu, pv);

    count[pu] += count[pv];
    par[pv] = pu;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;

    vector<ll> par(n+1), count(n+1);
    for(int i=0; i<=n; i++){
        par[i] = i;
        count[i] = 1;
    }

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        join(u,v, par, count);
    }

    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(par[i] == i) ans.push_back(i);
    }

    int sz = ans.size();
    cout<<sz-1<<endl;
    for(int i=1; i<sz; i++) cout<<ans[i-1] <<" "<<ans[i]<<endl;
    
    return 0;
}

// JAVA

public class Main{
  static int find(int x, int [] par){
        if(x == par[x]) return x;
        return par[x] = find(par[x], par);
    }

    static void join(int u, int v, int [] par, long [] count){
        int pu = find(u, par), pv = find(v, par);

        if(par[pu] == par[pv])  return;

        if(count[pu] < count[pv]){
            int temp = pu;
            pu = pv;
            pv = temp;
        }

        count[pu] += count[pv];
        par[pv] = pu;
    }
 
    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        FastWriter so = new FastWriter();

        int n = sc.nextInt(), m = sc.nextInt();

        int par[] = new int[n+1];
        long count[] = new long[n+1];
        for(int i=0; i<=n; i++){
            par[i] = i;
            count[i] = 1;
        }

        for(int i=0; i<m; i++){
            int u = sc.nextInt(), v = sc.nextInt();

            join(u,v, par, count);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=1; i<=n; i++){
            if(par[i] == i) ans.add(i);
        }

        int sz = ans.size();
        so.println(sz-1);
        for(int i=1; i<sz; i++) so.println(ans.get(i-1) + " " + ans.get(i));
 
        so.flush();
        so.close();
        sc.close();
    }
}
