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
    cin >> n >> k;
    vector <int> a(n),b(n);
    Auto(i,a)cin >> i;
    Auto(i,b)cin >> i;
    vector<vector<int>>dp(k+1,vector<int>(1601,-1));
    dp[0][0] = 0;
    for(int i = 0;i<n;i++){
        int val = a[i];
        for(int j = k-1;j>=0;j--){
            for(int s = 0;s<=1600;s++){
                if(dp[j][s] != -1){
dp[j+1][s+val] = max(dp[j+1][s+val],dp[j][s]+b[i]); 
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<=1600;i++){
        ans = max(ans,min(dp[k][i],i));
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    Rep(i, 1, t + 1)solve();
    return 0;
}
