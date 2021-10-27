#include<bits/stdc++.h>
using namespace std;
vector <int> adj[1000001];
int color[1000001];
int node,edge;
bool dfs(int s){
   for(auto it : adj[s]){
       if(color[it] == -1){
           color[it] = 1 - color[s];
           if(!dfs(it))return false;
       }else if(color[it] == color[s])return false;
   }
   return true;
}
bool IsBipartite(){
    for(int i = 1;i<=node;i++){
        if(color[i] == -1){
            color[i] = 1;
            if(!dfs(i))
                return false;
        }
    }
    return true;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Practice.txt","r",stdin);
    #endif
    int test,Case = 1;cin >> test;
    while(test--){
        cin >> node >> edge;
        for(int i =1;i<=node;i++)adj[i].clear(),color[i] = -1;
        for(int i =1;i<=edge;i++){
            int u,v;cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << "Scenario #" << Case++ << ":\n";
        if(IsBipartite())
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";
    }
    return 0;
}