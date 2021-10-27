#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector <int> graph[1000];
vector <int> path;
bool vis[1000];
vector <int> dist(1000),parents(1000);
void bfs(int Source)
{
    queue<int> q;
    vis[Source] = 1;
    dist[Source] = 0;
    parents[Source] = -1;
    q.push(Source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        path.push_back(node);
        rep(i, graph[node].size())
        {
            int next = graph[node][i];
            if (!vis[next])
            {
                vis[next] = 1;
                dist[next] = dist[node] + 1;
                parents[next] = node;
                q.push(next);
            }
        }
    }
}
int main()
{
    freopen("Input.txt", "r", stdin);
    int V, E;
    cin >> V >> E;
    rep(i, E)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int Source;
    cin >> Source;
    bfs(Source);
    cout << "From node " << Source << '\n';
    for (int i = 1; i <= V; i++)
    {
        cout << "Distance of " << i << " is : ";
        cout << dist[i] << '\n';
    }
    cout << "BFS = ";
    rep(i,path.size())
    cout << path[i] << ' ';
    cout << '\n';
    int u;cin >> u;
    if(!vis[u]){
        cout << "No Path!!" << '\n';
    }else{
        vector <int> shortest_path;
        for(int v = u;v != -1 ;v = parents[v]){
            shortest_path.push_back(v);
        } 
        reverse(shortest_path.begin(),shortest_path.end());
        cout << "Shortest Path from " << u << " to " << Source << " : ";
        for(auto v : shortest_path){
            cout << v << ' ';
        }
        cout << '\n';
    }
    return 0;
}