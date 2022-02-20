#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll median = a[n/2];
    ll ans = 0;
    for(ll i : a){
        ans += abs(median - i);
    }
    cout << ans << "\n";
    return 0;
}