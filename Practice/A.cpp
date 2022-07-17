#include <bits/stdc++.h>
#define pb push_back
#define all(var) var.begin(), var.end()
#define rall(var) var.rbegin(), var.rend()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 1e9+7;
const ll Inf = 1e18;
const int MaxN = 4e5+10;
void solve(){
    ll n,l,r;
    cin >> n >> l >> r;
    vector<ll>a;
    set <int> s;
    for(ll x = l,i = 1; x <= r && i<=n ; x++,i++){
        int m = gcd(i,x);
        if(!s.count(m)){
            s.insert(m);
            a.pb(x);
        }
    }
    for(auto i : a){
        cout << i << " ";
    }cout << '\n';
    for(auto i : s){
        cout << i << " ";
    }cout << '\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
    #endif
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}