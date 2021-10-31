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

const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int SIZE = 1e6 + 10;
const ll MOD = 1e9 + 7;

int SetBit(ll n, ll X) { return n | (1LL << X); }
int ClearBit(ll n, ll X) { return n & ~(1LL << X); }
int ToggleBit(ll n, ll X) { return n ^ (1LL << X); }
bool CheckBit(ll n, ll X) { return (bool)(n & (1LL << X)); }
int CountBit(ll n) { return __builtin_popcountll(n); }

ll arr[SIZE], pre_sum[SIZE];
ll n, m, p, q, l, r, k, x, y, z, ans, sum;

void solve(){
    ans = 0;
    cin >> n;
    Rep(i,1,n+1){
        cin >> x;
        ans = max(ans,x-i); // BCZ we can simply put ans number of 1 at the beggining of the array.
    }
    cout << ans << '\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("codeforces.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    Rep(i, 1, t + 1)
        //cout << "Case #" << i << ": ",
        solve();
    return 0;
}
