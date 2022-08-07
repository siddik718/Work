#include <bits/stdc++.h>
#define pb push_back
#define all(var) var.begin(), var.end()
#define rall(var) var.rbegin(), var.rend()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 1e9+7;
const ll mod = 998244353;
const ll Inf = 1e18;
const int MaxN = 2e5+10;
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    rep(i,0,n-1)cin >> a[i];
    vector<pair<int,int>> ans;
    int in = -1;
    rep(i,1,n-1){
        if(a[i] != a[0]){
            ans.pb({0,i});
            in = i;
        }
    }
    if(in == -1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rep(i,1,n-1){
        if(a[i] == a[0]){
            ans.pb({i,in});
        }
    }
    for(auto [x,y]: ans){
        cout << x+1 << " " << y+1 << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
    #endif
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}