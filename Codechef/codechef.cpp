#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define Auto(it, v) for (auto &it : v)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, a, n) for (int i = a; i < (n); i++)

using ll = long long int;
using namespace std;

const ll inf = 1e9 + 7;
const ll INF = 1e18 + 10;

ll n, m, p, q, l, r, k, x, y, z, ans, sum;

void solve(){
    string a,ans = "";
    cin >> n >> a;
    ll cnt1 = count(all(a),'1');
    ll cnt0 = n - cnt1;
    if(min(cnt0,cnt1) == 0)ans = "BOb";
    else if(min(cnt1,cnt0) == 1)ans = "Alice";
    else{
        if(n&1)ans = "Alice";
        else ans = "Bob";
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    Rep(i, 1, t + 1)solve();
    return 0;
}
