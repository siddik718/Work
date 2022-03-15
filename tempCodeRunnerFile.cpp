#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105;
ll a[N],n,k;
bool good(ll B){
    for(int i = 0;i<n;i++){
        if(abs(a[i]-B) > k) return false;
    }
    return true;
}
int main(){
    int q;cin >> q;
    while(q--){
        cin >> n >> k;
        for(int i=0;i<n;i++)cin >> a[i];
        ll l = 0,r = 1e14,m,ans = -1;
        while(l<r){
            m = l + (r-l)/2;
            if(good(m))l = m+1,ans = l;
            else r = m;
        }
        cout << l << " " << r << endl;
    }
    return 0;
}