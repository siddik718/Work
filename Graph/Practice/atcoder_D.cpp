#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
using namespace std;
vector <int> adj[1000];
int indegree[1000];
int n,e;
void Topological_Sort()
{
    //queue <int> q;
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i = 1;i<=n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    for(int i = 1;i<=n;i++){
        if(!indegree[i])heap.push(i);
    }
    vector <int> topo;
    while(!heap.empty()){
        int u = heap.top();
        heap.pop();
        topo.push_back(u);
        for(auto v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0)heap.push(v);
        }
    }
    if(topo.size() != n){cout << -1 ; return;}
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
    Topological_Sort();
    return 0;
}