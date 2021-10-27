#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector <int> adj[1000];
int color[1000];
int node,edge;
bool dfs(int s)
{
    for(auto it : adj[s]){
        if(color[it] == -1){
            color[it] = 1 - color[s];
            if(!dfs(it))return false;
        }else if(color[it] == color[s])return false;
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
            color[i] = 1;
            if(!dfs(i))
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