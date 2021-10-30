#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve(){
    int n;cin >> n;
    vector <pair<int,int>> v(n);
    for(int i=0;i<n;i++)cin >> v[i].first >> v[i].second;
    sort(v.begin(),v.end());
    int ans = -1;
    for(int i=0;i<n;i++){
        if(ans <= v[i].second)
            ans = v[i].second;
        else
            ans = v[i].first;
    }
    cout << ans ;
}
int main(){
   #ifndef ONLINE_JUDGE
   freopen("Dead_End.txt", "r", stdin);
   #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);cout.tie(0);
    //int t;
    //cin >> t;
    //while (t--)
        solve();
    return 0;
}
