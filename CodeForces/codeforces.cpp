/***
 * Bismillahir Rahmanir Rahim
 * Author:  Abu Bakar Siddik(City University-53 Batch , Dhaka)
 ***/
#include <bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define Auto(it, v) for (auto &it : v)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, a, n) for (int i = a; i < (n); i++)

using ll = long long int;
using namespace std;

const int inf = 1e9 + 7;
const ll INF = 1e18 + 10;

int SetBit(ll n, ll X) { return n | (1LL << X); }
int ClearBit(ll n, ll X) { return n & ~(1LL << X); }
int ToggleBit(ll n, ll X) { return n ^ (1LL << X); }
bool CheckBit(ll n, ll X) { return (bool)(n & (1LL << X)); }
bool isPowerOf2(ll X) {return X && ( !(X & (X-1) ) ) ; }
int CountBit(ll n) { return __builtin_popcountll(n); }

ll n, m, p, q, l, r, k, x, y, z, ans, sum;

void solve(){
    cin >> n;
    string a;cin >> a;
    int cnt = 0;
    rep(i,n-1){
        if(a[i]>a[i+1] && cnt == 0){
            cnt++;
            continue;
        }
        cout << a[i];
    }
    if(cnt)cout << a.back();
    cout << '\n';
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int t;cin >> t;
    // Rep(i, 1, t + 1)
        //cout << "Case #" << i << ": ",
         solve();
    return 0;
}
