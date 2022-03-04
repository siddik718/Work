#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    for(auto &i : a)cin >> i;
    sort(a.begin(),a.end());
    ll ans = 1;
    for(auto i : a){
        if(i<=ans)ans+=i;
    }
    cout << ans << endl;
    return 0;
}