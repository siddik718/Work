#include <bits/stdc++.h>
#define pb push_back
#define all(var) var.begin(), var.end()
#define rall(var) var.rbegin(), var.rend()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 1e9+7;
const ll Inf = 1e18;
const int MaxN = 4e5+10;
void maxSubarraySum(int a[],int n){
    int max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < n; i++){
        if (a[i]+max_ending_here >= a[i]){
            max_ending_here += a[i];
        }
        else{
            max_ending_here = a[i];
        }
        max_so_far = max(max_so_far, max_ending_here);
    }
    cout<<max_so_far<<endl;
}
void print(int a[],int n){
    rep(i,0,n-1){
        cout << a[i] << ' ';
    }
    cout << endl;
}
void solve(){
    int n, m;
    cin >> n >> m;
    int a[n];
    rep(i,0,n-1)cin >> a[i];
    maxSubarraySum(a,n);
    // print(a,n);
    while(m--){
        int i, v;
        cin >> i >> v;
        a[i] = v;
        maxSubarraySum(a,n);
        //print(a,n);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
    #endif
    int t=2;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}