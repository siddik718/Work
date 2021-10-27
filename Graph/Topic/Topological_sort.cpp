/**
 * @file Topological_sort.cpp
 * @author Abu Bakar Siddik(City University 53-Batch,Dhaka)
 * @date 2021-10-18
 * In computer science, a topological sort or topological ordering of a directed graph is a linear
 * ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.
 * Has To be DAG(Directed Acycilc Graph)
 */

#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
using namespace std;
vector <int> adj[1000];
//int vis[1000];
int n,e;
/**
 * stack <int> s;
 * Using Dfs : 
void dfs(int v)
{
    vis[v] = 1;
    for(auto u : adj[v]){
        if(!vis[u])
        {
            dfs(u);
        }
    }
    s.push(v);
}
void Topological_Sort()
{
    for(int i = 0;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    while(!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}
**/
int indegree[1000];
void Topological_Sort()
{
    queue <int> q;
    for(int i = 1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    for(int i = 1;i<=n;i++){
        if(!indegree[i])q.push(i);
    }
    vector <int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(auto v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0)q.push(v);
        }
    }
    for(auto it : topo)cout << it << ' ';
    cout << '\n';
}
int main()
{
    freopen("Input.txt","r",stdin);
    cin >> n >> e;
    for(int i = 1;i<=e;i++)
    {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
    }
   // memset(vis,0,sizeof(vis));
    Topological_Sort();
    return 0;
}