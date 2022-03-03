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
void solve(){
    vector <int> a(31,1);
    for(int i = 1;i<=30;i++){
        if(i%7 == 0 || i%7 == 7)a[i] = 0;
    }
    int n,m;
    cin >> n;
    rep(i,n){
        cin >> m;
        a[m] = 0;
    }
    int cnt = 0;
    rep(i,31)cnt += a[i]==0;
    cout << cnt << endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--)
    solve();
    return 0;
}