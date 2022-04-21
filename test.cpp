#include<bits/stdc++.h>
#define rep(i,a,n) for(ll i = (a); i <= (n); i++)
using namespace std;
using ll = long long;
int main(){
    int T;cin >> T;
    while(T--){
        ll n,m;cin >> n >> m;
        if(n<m)swap(n,m);
        ll ans = 0;
        if(m == 1 && n>2)ans=-1;
        else{
            ans = 2 * ( m - 1) + 2 * ( n - m ) + (n-m) % 2;
        }
        cout << ans << endl;
    }
    return 0;
}