/***
 * Author: 😅😄¯\_(ツ)_/¯😔
 ***/
#include <bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define Auto(it, v) for (auto &it : v)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define For(i, a, n) for (int i = a; i < (n); i++)

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
bool ckmax(int& a, const int& b) {return a < b ? a = b, true : false;}
bool ckmin(int& a, const int& b) {return a > b ? a = b, true : false;}
ll n, m, p, q, l, r, k, x, y, z, ans, sum;
const int N = 100;
class solution{
    
    public:
        void solve(){
            cin >> n >> k;
            vector <ll> a(n);
            FOR(i,n)cin >> a[i];
            sort(all(a));
            ans = 0;
            int lst = n-1;
            while(k--){
                int flag = 0;
                for(int i = a.size()-1;i>=0;i--){
                    if(a[i]<a[lst] && a[i] > 0 && a[lst]>0){
                        flag = 1;
                        ans += a[i]/a[lst];
                        a[i] = 0;
                        a[lst]=0
                        lst--;
                    }
                }
                if(!flag)break;
            }
            while(k--){
                ll last = a.back();a.pop_back();
                int flag = 0;
                for(int i = a.size()-1;i>=0;i--){
                    if(a[i]<=last && a[i] > 0){
                        flag = 1;
                        ans += a[i]/last;
                        a[i] = 0;
                    }
                }
                if(!flag)break;
            }
            for(int i : a){
                if()
            }
            cout << ans << endl;
        }
};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    For(i,1,t+1){
        //cout << "Case #" << i << ": ";
        solution WAAAAAAAAA;
        WAAAAAAAAA.solve();
    }
    return 0;
}
