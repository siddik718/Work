#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll binpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1)
            res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int a,n,k;cin >> n >> k;
    ll mx = 0;
    for(int i = 0;i<n;i++){
        cin >> a;
        ll x = binpow(10LL,a);
        mx = max(mx,x);
    }
    ll ans = k*mx;
    cout << ans << '\n';
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("116.txt", "r", stdin);
   #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
