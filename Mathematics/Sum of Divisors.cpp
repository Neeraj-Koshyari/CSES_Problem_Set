// Solution Link: https://youtu.be/JqWiWJQOQyU?si=Ay1-OoKgoOiQN9em

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll modP(ll x, ll y, ll mod){
    ll ans = 1;
    while(y){
        if(y&1) ans = (ans * x)%mod;
        
        x = (x*x)%mod;
        y /= 2;
    }

    return ans;
}

ll sumN(ll val, ll mp2, ll mod){
    ll x = val % mod;
    ll y = (val + 1) % mod;
    ll ans = (((x*y)%mod)*mp2)%mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;

    ll ans = 0, next = 1, mod = 1e9+7;
    ll mp2 = modP(2ll, mod-2, mod);
    while(next <= n){
        ll q = n/next, prev = next;
        next = n/q + 1;

        ll val = (sumN(next-1, mp2, mod) - sumN(prev-1, mp2, mod) + mod) % mod;
        ans = (ans + (val * q) % mod) % mod;
    }
    cout<<ans<<endl;
    
    return 0;
}
