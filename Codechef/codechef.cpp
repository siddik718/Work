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
    cin >> n >> m;
    vector <ll> a(n),b(m);
    ll sum_a = 0,sum_b = 0;
    Auto(i,a)cin >> i,sum_a += i;
    Auto(i,b)cin >> i,sum_b += i;
    sort(all(a));sort(all(b),greater<ll>());
    int ans = 0;
    while((sum_b>=sum_a ) and (ans < min(n,m))){
        sum_b -= b[ans];
        sum_b += a[ans];
        sum_a -= a[ans];
        sum_a += b[ans];
        ans++;
    }
    cout << (sum_a>sum_b?ans:-1) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    Rep(i, 1, t + 1)solve();
    return 0;
}
