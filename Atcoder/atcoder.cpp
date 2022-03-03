#include <bits/stdc++.h>
using ll = long long int;
using ld = long double;
using namespace std;
void solve(){
    ll q;cin >> q;
    multiset <ll> s;
    while(q--){
        ll t;cin >> t;
        if(t == 1){
            ll x;cin >> x;
            s.insert(x);
        }else if(t == 2){
            ll x,k;cin >> x >> k;
            auto it = s.upper_bound(x);
            ll ans = -1;
            for(int i = 1;i<=k;i++){
                if(it == s.begin()){
                    ans = -1;
                    break;
                }else{
                    it = prev(it);
                    ans = *it;
                }
            }
            cout << ans << endl;
        }else{
            ll x,k;cin >> x >> k;
            auto it = s.lower_bound(x);
            ll ans = -1;
            for(int i = 1;i<=k-1;i++){
                if(it == s.end()){
                    ans =-1;
                    break;
                }else{
                    ans = *it;
                    it = next(it);
                }
            }
            cout << *it << endl;
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
