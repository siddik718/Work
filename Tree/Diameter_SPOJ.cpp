#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
 
vector<int>adj[N];
vector<int>path;

// int n,c,d[N];
// void dfs(int u,int p){
//     for(auto v : adj[u]){
//         if(v == p)continue;
//         d[v] = d[u] + 1;
//         if(d[v]>d[c]){c=v;path.push_back(c);}
//         dfs(v,u);
//     }
// }
 
// pair<int,int> bfs(int x){
//     queue<pair<int,int>>q;
//     q.push({x,0});
//     vector<int>vis(n+1,0);
//     pair<int,int> u;
//     while(!q.empty()){
//         u = q.front();q.pop();
//         vis[u.first] = true;
//         for(auto v : adj[u.first]){
//             if(!vis[v])q.push({v,u.second+1});
//         }
//     }
//     return u;
// }
 
int n,d,d1[N],d2[N];
 
void dfs(int u,int p){
    d1[u]=d2[u]=0;
    for(auto v : adj[u]){
        if(v==p)continue;
        dfs(v,u);
        int t = d1[v]+1;
        if(t > d1[u]){
            d2[u]=d1[u];
            d1[u]=t;
        }else if(t > d2[u]){
            d2[u]=t;
        }
        d=max(d,d1[u]+d2[u]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // work's only when positive edges.
    // dfs(1,0);path.clear();path.push_back(c);d[c]=0;dfs(c,0);for(auto i : path)cout<<i<<' ';cout<<'\n';cout<<d[c]<<'\n';using 2 DFS
    // auto u=bfs(1);auto v=bfs(u.first);cout<<v.second<<'\n';using 2 BFS
    
    // work's on both.
    // dfs(1,0);cout<<d<<'\n';//single dfs with DP.
 
}