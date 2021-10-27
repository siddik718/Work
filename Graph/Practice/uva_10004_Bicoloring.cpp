/**
 * Problem: uva_10004_Bicoloring.cpp
 * Author: Abu Bakar Siddik(City University-53-batch,Dhaka)
 * Date: 2021-10-17
 * Just Check if The Graph is Bipartite Or Not ..
 **/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector<int> adj[1000];
int color[1000];
int node, edge;
bool bfs(int s)
{
    queue<int> q;
    q.push(s);
    color[s] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : adj[v])
        {
            if (color[u] == -1)
            {
                color[u] = 1 - color[v];
                q.push(u);
            }
            else if (color[u] == color[v])
                return false;
        }
    }
    return true;
}
int main()
{
    freopen("Input.txt", "r", stdin);
    while (1)
    {
        int V, E;
        cin >> V;
        if (V == 0)
            break;
        cin >> E;
        rep(i, V + 1) adj[i].clear();
        rep(i, E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(color, -1, sizeof(color));
        bool ok = true;
        for (int i = 1; i <= V; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i))
                {
                    cout << "NOT BICOLORABLE.\n";
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
            cout << "BICOLORABLE.\n";
    }
    return 0;
}