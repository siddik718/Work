#include<bits/stdc++.h>
using namespace std;
int node,edge;
vector <int> adj[1000];
vector <int> dfs_path;
int time_in[1000],time_out[1000],color[1000];
int dfs_timer = 0;
void dfsvis(int x){
    time_in[x] = dfs_timer;
    dfs_timer++;
    color[x] = 1;
    dfs_path.push_back(x);
    for(auto it : adj[x]){
        if(color[it] == 0){
            dfsvis(it);
        }
    }
    color[x] = 2;
    time_out[x] = dfs_timer;
    dfs_timer++;
}
void dfs(){
    for(int i = 1;i<=node;i++)color[i] = 0;
    for(int i = 1;i<=node;i++){
        if(color[i] == 0){
            dfsvis(i);
        }
    }
    for(auto it : dfs_path)
        cout << it << ' ';
    cout << '\n';
    for(int i = 1;i<=node;i++)
    {
        cout << "For Node = " << i << ' '; 
        cout << "Time In = " << time_in[i] << ' ';
        cout << "Time Out = " << time_out[i] << '\n';
    }
}
int main()
{
    freopen("Input.txt","r",stdin);
    cin >> node >> edge;
    for(int i = 1;i<=edge;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    return 0;
}