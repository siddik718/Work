#include <bits/stdc++.h>
#define F first
#define S second
#define rep(i,n) for(int i = 1;i<=n;i++)
using namespace std;
using ll = long long;
ll fact[10],ans;
vector <ll> dp;
ll f(int i){
    if(i == 10)return 1;
    ll x = f(i+1)*fact[i] ;
    ll y = f(i+1);
    if(x == ans){
        dp.push_back(x);
    }
    if(y == ans){
        dp.push_back(y);
    }
}
int main(){
    fact[0] = 1;
    rep(i,10){
        fact[i] = fact[i-1]*i;
    }
    auto solve = [&](){
        int n;
        cin >> n;
        ll a;ans = 1;
        cin >> a;
        while(a){
            ans *= fact[a%10];
            a /= 10;
        }
        ll x = f(2);
        for(auto m : dp)cout << m << " ";
        cout << endl;

    };
    freopen("input.in","r",stdin);
    // int t;cin >> t;
    // while(t--)
    solve();
    return 0;
}