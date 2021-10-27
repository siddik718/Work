#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector <int> adj[1000];
int color[1000];
int node,edge;
bool bfs(int s)
{
    queue <int> q;
    q.push(s);
    color[s] = 1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto u : adj[v])
        {
            if(color[u] == -1)
            {
                color[u] = 1 - color[v];
                q.push(u);
            }else if(color[u] == color[v])
                return false;
        }
    }
    return true;
}
bool IsBipartite()
{   
    memset(color,-1,sizeof(color));
    rep(i,node)
    {
        if(color[i] == -1)
        {
            if(!bfs(i))
                return false;
        }
    }
    return true;
}
int main()
{
    freopen("Input.txt", "r", stdin);
    cin >> node >> edge;
    rep(i,edge)
    {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(IsBipartite())
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}