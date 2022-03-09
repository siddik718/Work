/***
 * Bismillahir Rahmanir Rahim
 * Author:  Abu Bakar Siddik(City University-53 Batch , Dhaka)
 ***/
#include <bits/stdc++.h>
#define F first
#define S second
#define Max_N 100005
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i = 0;i<(n);i++)
#define Rep(i,a,n) for(int i = a;i<(n);i++)
#define per(i,n) for(int i = (n)-1;i>=0;i--)
#define Per(i,a,n) for(int i = (n)-1;i>=a;i--)
using namespace std;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 10;
int SetBit(ll n, ll X) { return n | (1LL << X); }
int ClearBit(ll n, ll X) { return n & ~(1LL << X); }
int ToggleBit(ll n, ll X) { return n ^ (1LL << X); }
bool CheckBit(ll n, ll X) { return (bool)(n & (1LL << X)); }
bool isPowerOf2(ll X) {return X && ( !(X & (X-1) ) ) ; }
int CountBit(ll n) { return __builtin_popcountll(n); }
bool ckmax(int& a, const int& b) {return a < b ? a = b, true : false;}
bool ckmin(int& a, const int& b) {return a > b ? a = b, true : false;}
ll compliment(ll x,ll n){return (x^(n-1));}
ll n, m, p, q, l, r, k, x, y, z, ans, sum;
vi right_shift(vi a){
    int n = a.size();
    vi x(n);
    Rep(i,1,n){
        x[i] = a[i-1];
    }
    x[0] = a[n-1];
    return x;
}
vi left_shift(vi a){
    int n = a.size();
    vi x(n);
    Rep(i,0,n-1){
        x[i] = a[i+1];
    }
    x[n-1] = a[0];
    return x;
}
void solve(){
    cin >> n;
    vi a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    vi tmp = b;ans = INT32_MIN;
    if(a == b)ans = n;
    else{
        while(true){
            ll m = 0;
            vi x = right_shift(b);
            if(x == b)break;
            rep(i,n){
                if(a[i] == x[i])m++;
            }
            ans = max(ans,m);
        }
    }
    cout << ans << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    Rep(i,1,t+1)
        // cout << "Case #" << i << ": ",
         solve();
    return 0;
}
