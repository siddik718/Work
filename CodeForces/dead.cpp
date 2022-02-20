#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
const int N = 1e5+5;
#define FOR(i,n) for(int i = 0;i<n;i++)
#define all(var) var.begin(),var.end()
vector <int> adj[N],vis(N,false);    
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v])dfs(v);
    }
}
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0;i<n;i++)cin >> a[i],vis[i] = false,adj[i].clear();
    for(int i = 0;i<n;i++){
        int j = i+1;
        while(a[i] > a[j] && j<n ){
            adj[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--)
    solve();
    return 0;
}