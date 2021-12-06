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
vector <ll> a;
void solve(){
    cin >> n >> m;
    string ans = "";
    if(m == n){
        rep(i,n+1)ans += "10";
    }else if(m > n){
        rep(i,n+1)ans += "10";
        rep(i,m-n-1)ans += "110";
        ans += "1";
    }else{
        rep(i,m)ans += "01";
        rep(i,n-m) ans += "010";
        ans += "0";
    }
    cout << ans.size() << "\n" << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    Rep(i, 1, t + 1)solve();
    return 0;
}
