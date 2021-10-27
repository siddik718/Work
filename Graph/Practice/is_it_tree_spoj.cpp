#include<bits/stdc++.h>
using namespace std;
vector <int> adj[20005];
int vis[20005];
void dfs(int x){
    vis[x] = 1;
    for(auto u : adj[x]){
        if(!vis[u])
        dfs(u);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Practice.txt","r",stdin);
    #endif
    int node,edge,cnt = 0;
    cin >> node >> edge;
    for(int i =1;i<=edge;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i =1;i<=node;i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt == 1 && (node== edge - 1))
    cout << "YES\n";
    else
    cout << "NO\n";
    return 0;
}