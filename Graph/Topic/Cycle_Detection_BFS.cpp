#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector <int> graph[1000];
bool vis[1000];
bool is_cycle(int x){
    queue<pair<int,int>> q;
    vis[x] = 1;
    q.push({x,-1});
    while (!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        rep(i, graph[node].size()){
            int next = graph[node][i];
            if (!vis[next]){
                vis[next] = 1;
                q.push({next,node});
            }
            else if(parent != next)
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("Input.txt", "r", stdin);
    int V, E;
    cin >> V >> E;
    rep(i, E){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i =1;i<=V;i++){
        if(!vis[i]){
            if(is_cycle(i)){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}