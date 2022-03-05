#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,n) for(int i = 0;i<n;i++)
#define For(i,a,n) for(int i = a;i<n;i++)
#define all(var) var.begin(),var.end()
#define pb push_back
#define F first
#define S second
void solve(){
    ll n;cin >> n;
    ll fact[15];
    fact[0] = 1;
    For(i,1,15)fact[i] = fact[i-1]*i;
    int ans = 100;
    FOR(i,(1<<14)){
        ll m = n;
        FOR(j,14){
            if(i&(1<<j)){
                m -= fact[j];
            }
        }
        if(m>=0){
            ans = min(ans,((__builtin_popcount(i)) + (__builtin_popcountll(m))));
        }
    }
    cout << ans << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--)solve();
    return 0;
}