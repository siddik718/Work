#include<bits/stdc++.h>
#define rep(i,a,n) for(int i = (a) ; i < (n) ; i++)
using namespace std;
using ll = long long int;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll test;cin >> test;
    while(test--){
        ll x0,n;
        cin >> x0 >> n;
        ll x = n / 4 * 4;
        //cout << "x = " << x << ' ';
        for(ll i = x+1;i<=n;i++){
            if(x0&1)x0 += i;
            else x0 -= i;
        }
        cout << x0 << '\n';
    }
    return 0;
}