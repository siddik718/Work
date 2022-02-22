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
ll n, m, p, q, l, r, k, x, y, z, ans, sum;
void solve(){
    cin >> n >> k;
    if(n == k){
        Rep(i,1,n+1) cout << i << " \n"[i==n];
        return;
    }
    cout << n-k+1 << " ";
    for(int i = 1;i<=n-k;i++)cout << i << " ";
    for(int i = n-k+2;i<=n;i++)cout << i << " \n"[i==n];
}
int main(){
    //cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--)
    solve();
    return 0;
}