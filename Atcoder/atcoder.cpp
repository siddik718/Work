#include <bits/stdc++.h>
using ll = long long int;
using ld = long double;
using namespace std;
const int N = 105;
int n,a[N],b[N],x,dp[N][10005];
int func(int i,int j){
    if(dp[i][j] != -1)return dp[i][j];
    dp[i][j] = 1;
    if(i>n)return 0;
    if(i+a[j]<=x){
        func(i+a[j],j+1);
    }
    if(i+b[j]<=x){
        func(i+b[j],j+1);
    }
    return 1;
}
void solve(){
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    memset(dp,-1,sizeof(dp));
    if(func(0,1) == 1)cout << "Yes\n";
    else cout << "No\n";    
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
