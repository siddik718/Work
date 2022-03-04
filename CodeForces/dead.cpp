#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,n) for(int i = 0;i<n;i++)
#define For(i,a,n) for(int i = a;i<n;i++)
#define all(var) var.begin(),var.end()
#define pb push_back
#define F first
#define S second
multiset <ll> pf;
void fuct(){
    ll a = 1,b = 1;
    For(i,1,17){
        b = a*i;
        pf.insert(a);
        a = b;
    }
}
void prework(){
    for(ll i = 0;i<=40;i++){
        ll x = (1ll<<i);
        pf.insert(x);
    }
}
void solve(){
    ll n;cin >> n;
    ll ans = 0;
    while(n>0){
        auto it = pf.upper_bound(n);
        if(it != pf.begin()){
            n -= *(--it);
            ans++;
        }else{
            cout << "-1\n";
            return;
        }
    }
    cout << ans << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    cin.tie(0)->sync_with_stdio(0);
    fuct();
    prework();
    int t;cin >> t;
    while(t--)solve();
    return 0;
}