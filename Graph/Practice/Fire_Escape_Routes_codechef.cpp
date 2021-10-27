#include<bits/stdc++.h>
using ll = long long int;
using namespace std;
const ll MOD = 1e9+7;
vector <int> adj[100005];
int vis[100005];
int cnt;
void dfs(int v){
    vis[v] = 1;
    for(auto u : adj[v]){
        if(!vis[u]){
            cnt++;
            dfs(u);
        }
    }
}
int main()
{
    //freopen("Practice.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int test;cin >> test;
    while(test--){
        int n,m;cin >> n >> m;
        for(int i = 1;i<=n;i++){
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i = 1;i<=m;i++){
            int u,v;cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        int first = 0,second = 1;
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                first++;
                cnt = 1;
                dfs(i);
                second = (second%MOD*cnt%MOD)%MOD;
            }
        }
        cout << first << ' ' << second << '\n';
    }
    return 0;
}