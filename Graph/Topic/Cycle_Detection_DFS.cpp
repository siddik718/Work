#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector <int> adj[1000];
bool vis[1000];
bool is_cycle(int x,int parent){
    vis[x] = 1;
    for(auto it : adj[x]){
        if(!vis[it]){
            if(is_cycle(it,x)) return true;
        }
        else if(it != parent)return true;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis,0,sizeof(vis));
    for(int i =1;i<=V;i++){
        if(!vis[i]){
            if(is_cycle(i,-1)){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}