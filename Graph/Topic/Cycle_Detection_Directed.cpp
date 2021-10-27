#include <bits/stdc++.h>
using namespace std;
vector <int> adj[1000];
int indegree[1000];
int node,edge;
// BFS:
bool Cycle()
{
    queue <int> q;
    for(int i = 1;i<=node;i++){
        for(auto u : adj[i]){
            indegree[u]++;
        }
    }
    for(int i = 1;i<=node;i++){
        if(indegree[i] == 0)q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for(auto v : adj[u]){
            indegree[v]--;
            if(!indegree[v])q.push(v);
        }
    }
    if(cnt == node)return false;
    else return true;
}
/** 
 * DFS:
 * int vis[1000];
 * int dfsvis[1000];
 bool Cycle(int s)
{
    vis[s] = 1;
    dfsvis[s] = 1;
    for(auto it : adj[s])
    {
        if(!vis[it])
        {
            if(Cycle(it))return true;
        }else if(dfsvis[it])return true;
    }
    dfsvis[s] = 0;
    return false;
}
**/
int main()
{
    freopen("Input.txt","r",stdin);
    cin >> node >> edge;
    for(int i = 1 ; i<=edge ; i++)
    {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
    }
   if(Cycle())
   cout << "Yes\n";
   else 
   cout << "No\n";
    return 0;
}