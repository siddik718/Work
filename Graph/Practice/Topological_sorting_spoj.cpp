#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("Practice.txt","r",stdin);
    #endif
    int n,m;
    cin >> n >> m;
    vector <int> adj[n+1];
    int indegree[n+1] = {0};
    for(int i = 1;i<=m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    //queue <int> q;
    priority_queue<int,vector <int>,greater<int>> q;
    for(int i =1;i<=n;i++){
        if(!indegree[i])q.push(i);
    }
    vector <int> topo;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        topo.push_back(u);
        for(auto v : adj[u]){
            indegree[v]--;
            if(!indegree[v])q.push(v);
        }
    }
    if(((int)topo.size()) != n)cout << "Sandro fails.\n";
    else{
        for(auto it : topo)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}