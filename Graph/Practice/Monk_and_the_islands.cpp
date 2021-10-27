#include<bits/stdc++.h>
using namespace std;
vector <int> adj[100005];
int dist[100005];
int vis[100005];
int n,m;
void bfs(){
    queue <int> q;
    q.push(1);
    dist[1] = 0;
    vis[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << dist[n] << '\n';
}
int main()
{
    //freopen("Practice.txt","r",stdin);
    int t;cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i<=n;i++)adj[i].clear(),vis[i] = 0,dist[i] = 0;
        for(int i = 1;i<=m;i++){
            int u,v;cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs();
    }
    return 0;
}
