#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int bfs(vector <int> adj[],int n){
    queue <int> q;
    q.push(1);
    vector <int> dist(n+1,inf),vis(n+1,0);
    dist[1] = 0;
    vis[1] = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist[n];
}
int main()
{
    int n,m;cin >> n >> m;
    bool tmp[n+1][n+1];
    memset(tmp,false,sizeof(tmp));
    for(int i = 1;i<=m;i++){
        int u,v;cin >> u >> v;
        tmp[u][v] = true;
        tmp[v][u] = true;
    }
    vector <int> rail[n+1],bus[n+1];
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(tmp[i][j]){
                rail[i].push_back(j);
                rail[j].push_back(i);
            }
            else{
                bus[i].push_back(j);
                bus[j].push_back(i);
            } 
        }
    }
    int x = bfs(rail,n);
    int y = bfs(bus,n);
    int ans = max(x,y);
    if(ans == inf)ans = -1;
    cout << ans << '\n';
    return 0;
}