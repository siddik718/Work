/***
 * Bismillahir Rahmanir Rahim
 * Author:  Abu Bakar Siddik(City University-53 Batch , Dhaka)
 ***/
#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define FOR(i,n) for(int i = 0;i<(n);i++)

using ll = long long int;
using namespace std;
void solve(){
    ll n,m;
    cin >> n >> m;
    vector <ll> adj[n+1];
    FOR(i,m){
        ll a,b;cin >> a >> b;
        if(a != b){
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }
    ll cnt = 0;
    FOR(i,n){
        ll x = adj[i+1].size(); 
        if(x > 2){
            cout << "No\n";
            return;
        }
        if(x == 2)cnt++;
    }
    if(cnt >= (int)(ceil(n/2.0)) ) {
        cout << "No\n";
        return ;
    }
    cout << "Yes\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("atcoderI.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int t;cin >> t;
    // while(t--)
    solve();
    return 0;
}
