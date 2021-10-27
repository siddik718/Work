#include<bits/stdc++.h>
using namespace std;
vector <int> adj[1000005];
int indegree[1000005];
int n,e;
void Sort(){
    queue <int> q;
    for(int i = 1;i<=n;i++){
        if(indegree[i] == 0)q.push(i);
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
    if(((int)topo.size()) != n){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(auto it : topo)cout << it << '\n';
}
int main()
{
    freopen("Practice.txt","r",stdin);
    while(cin >> n >> e){
        if(n == 0 && e == 0)break;
        for(int i = 1;i<=n;i++)adj[i].clear(),indegree[i] = 0;
        for(int i = 1;i<=e;i++){
            int u,v;cin >> u >> v;
            adj[u].push_back(v);
            indegree[v]++;
        }
        Sort();
    }
    return 0;
}