/**
 * @file Shortest_Path_in_DAG_with_Weights.cpp
 * @date 2021-10-18
 */
#include<bits/stdc++.h>
const long long inf = 1e9+10;
using namespace std;
vector <pair<int,int>> adj[1000];
stack <int> s;
int vis[1000];
int node,edge;
void dfs(int x){
    vis[x] = 1;
    for(auto u : adj[x]){
        if(!vis[u.first]){
            dfs(u.first);
        }
    }
    s.push(x);
}
int dist[1000];
void Sort()
{
    memset(vis,0,sizeof(vis));
    for(int i = 0;i<node;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    memset(dist,inf,sizeof(dist));
    dist[0] = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(dist[u] != inf){
            for(auto it : adj[u]){
                if(dist[u]+it.second < dist[it.first]){
                    dist[it.first] = dist[u]+it.second;
                }
            }
        }
    }
    for(int i = 0;i<node;i++){
        cout << "Distance Between " << 0 << " To " << i << " is = ";
        cout << ((dist[i] == inf) ? inf : dist[i]) << "\n";
    }
    cout << '\n';
}
int main()
{
    freopen("Input.txt","r",stdin);
    cin >> node >> edge;
    for(int i = 0;i<edge;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    Sort();
    return 0;
}