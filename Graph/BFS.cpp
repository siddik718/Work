/**
 * @file BFS.cpp
 * @author Abu Bakar Siddik (absiddik718@gmail.com)
 * @brief To finds the shortest path ina any graph .
 * @date 2021-12-09
 */
/**
 * Find the shortest path,distance of other node from a source node in an unweighted graph.
 */
// Ans:
// #include<bits/stdc++.h>
// using namespace std;
// vector <int> adj[100],vis(100),dist(100),par(100);
// int n,m;
// void bfs(int u){
//     queue <int> q;
//     dist[u] = 0;
//     par[u] = -1;
//     vis[u] = 1;
//     q.push(u);
//     while(!q.empty()){
//         int v = q.front();q.pop();
//         for(auto it : adj[v]){
//             if(!vis[it]){
//                 vis[it] = 1;
//                 q.push(it);
//                 dist[it] = dist[v] + 1;
//                 par[it] = v;
//             }
//         }
//     }
// }
// int main(){
//     cin >> n >> m;
//     for(int i = 1;i<=m;i++){
//         int a,b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     int s;cin >> s;
//     bfs(s);
//     cout << "From Node " << s << " To Other Node : \n";
//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Distance of " << i << " is : ";
//         cout << dist[i] << '\n';
//     }
//     int u;cin >> u;
//     if(!vis[u]){
//         cout << "No Path\n";
//     }else{
//         vector <int> path;
//         for(int v = u;v != -1;v = par[v]){
//             path.push_back(v);
//         }
//         cout << "Path : ";
//         reverse(path.begin(),path.end());
//         for(auto v : path)cout << v << " ";
//         cout << '\n';
//     }
//     return 0;
// }