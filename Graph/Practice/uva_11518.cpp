#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
using namespace std;
vector <int> adj[10001];
int vis[10001],cnt;
void dfs(int n){
    cnt++;
    vis[n] = 1;
    for(auto it : adj[n]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
int main(){
    int test;cin >> test;
    while(test--){
        int n,m,l;cin >> n >> m >> l;
        rep(i,n+1)adj[i].clear(),vis[i] = 0;cnt = 0;
        rep(i,m){
            int u,v;cin >> u >> v;
            adj[u].push_back(v);
           // adj[v].push_back(u);
        }
        rep(i,l){
            int x;cin >> x;
            if(!vis[x]){
                dfs(x);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}