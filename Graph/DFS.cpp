/**
 * @file DFS.cpp
 * @author Abu Bakar Siddik (absiddik718@gmail.com)
 * @date 2021-12-08
 */
/**
 * DFS Finds the lexicographical first path int grapg from
 * source to any other vertix.
 * It find the shortest paths in a tree (as there exixts a sipmle path).
 * */
/***
 * Find any path in the graph from source vertex u to all vertices.
 ***/
// Ans:
// #include<bits/stdc++.h>
// using namespace std;
// vector <int> adj[100],path;
// int vis[100];
// int V,E;
// void dfs(int u){
//     vis[u] = 1;
//     path.push_back(u);
//     for(auto v : adj[u]){
//         if(!vis[v]){
//             dfs(v);
//         }
//     }
// }
// int main(){
//     cin >> V >> E;
//     for(int i = 1;i<=E;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int source;cin >> source;
//     dfs(source);
//     for(auto it : path)cout << it << " ";
//     cout << "\n";
//     return 0;
// }
/***
 * Find lexicographical first path in the graph from source u to all vertices.
***/
// Ans:
// #include<bits/stdc++.h>
// using namespace std;
// vector <int> adj[100],path;
// int vis[100];
// int V,E;
// void dfs(int u){
//     vis[u] = 1;
//     path.push_back(u);
//     for(auto v : adj[u]){
//         if(!vis[v]){
//             dfs(v);
//         }
//     }
// }
// int main(){
//     cin >> V >> E;
//     for(int i = 1;i<=E;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     for(int i = 1;i<=V;i++){
//         sort(adj[i].begin(),adj[i].end());
//     }
//     int source;cin >> source;
//     dfs(source);
//     for(auto it : path)cout << it << " ";
//     cout << "\n";
//     return 0;
// }
/***
 * Check if a vertex in a tree is an ancestor of some other vertex
***/
// Ans:
// #include<bits/stdc++.h>
// using namespace std;
// vector <int> adj[100];
// int Entry[100],Exit[100],color[100];
// int V,E,dfs_timer = 0;
// void dfs(int u){
//     Entry[u] = dfs_timer++;
//     color[u] = 1;
//     for(auto v : adj[u]){
//         if(color[v] == 0){
//             dfs(v);
//         }
//     }
//     color[u] = 2;
//     Exit[u] = dfs_timer++;
// }
// int main(){
//     cin >> V >> E;
//     for(int i = 1;i<=E;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     dfs(1);
//     int checkNode;cin >> checkNode;
//     for(int j = 1;j<=V;j++){
//         if(j != checkNode && Entry[checkNode] < Entry[j] && Exit[checkNode] > Exit[j]){
//             cout << "Yes\n";
//             return 0;
//         }    
//     }
//     cout << "No\n";
//     return 0;
// }
/***
 * Topological sorting:
 ***/
//Ans:Remember the graph has to DAG(Directed Acyclic Graph)
// #include<bits/stdc++.h>
// using namespace std;
// vector <int> adj[100];
// stack <int> s;
// int V,E,vis[100];
// void dfs(int u){
//     vis[u] = 1;
//     for(auto v : adj[u]){
//         if(!vis[v])dfs(v);
//     }
//     s.push(u);
// }
// void Sort()
// {
//     for(int i = 0;i<=V;i++){
//         if(!vis[i])dfs(i);
//     }
//     while(!s.empty()){
//         cout << s.top() << " ";
//         s.pop();
//     }
//     cout << '\n';
// }
// int main(){
//     cin >> V >> E;
//     for(int i = 1;i<=E;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//     }
//     Sort();
//     return 0;
// }
/***
 * Cycle detection in a graph(complexity O(N+M)).
 ***/
// #include <bits/stdc++.h>
// using namespace std;
// int V,E;
// vector <int> adj[100];
// int vis[100];
// bool dfs(int u,int par){
//     vis[u] = 1;
//     for(auto v : adj[u]){
//         if(!vis[v]){
//             if(dfs(v,u))return true;
//         }else if(v != par)return true;
//     }
//     return false;
// }
// int main(){
//     cin >> V >> E;
//     for(int i = 1;i<=E;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     for(int i = 1;i<=V;i++){
//         if(!vis[i]){
//             if(dfs(i,-1)){
//                 cout << "YES\n";
//                 return 0;
//             }
//         }
//     }
//     cout << "NO\n";
//     return 0;
// }
/*
Checking a graph for acyclicity and finding a cycle in O(M).
https://cp-algorithms.com/graph/finding-cycle.html
*/
//Ans:
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// vector<int> adj[1000];
// vector<bool> visited;
// vector<int> parent;
// vector<int> color;
// int cycle_start, cycle_end;
// For Undirected:
// bool dfs(int v, int par) {
//     visited[v] = true;
//     for (int u : adj[v]) {
//         if(u == par) continue;
//         if (visited[u]) {
//             cycle_end = v;
//             cycle_start = u;
//             return true;
//         }
//         parent[u] = v;
//         if (dfs(u, parent[u]))
//             return true;
//     }
//     return false;
// }
// For Directed:
// bool dfs(int v){
//     color[v] = 1;
//     for(auto u : adj[v]){
//         if(color[u] == 0){
//             parent[u] = v;
//             if(dfs(u))return true;
//         }else if(color[u] == 1){
//             cycle_end = v;
//             cycle_start = u;
//             return true;
//         }
//     }
//     color[v] = 2;
//     return false;
// }
// void find_cycle() {
//     // visited.assign(n, false);// undirected.
//     color.assign(n,0);//directed.
//     parent.assign(n, -1);
//     cycle_start = -1;
//     for (int v = 0; v < n; v++) {
//         // if (!visited[v] && dfs(v, parent[v]))
//         //     break; // undirected.
//         if(color[v] == 0 && dfs(v))break;//directed.
//     }
//     if (cycle_start == -1) {
//         cout << "Acyclic" << endl;
//     } else {
//         vector<int> cycle;
//         cycle.push_back(cycle_start);
//         for (int v = cycle_end; v != cycle_start; v = parent[v])
//             cycle.push_back(v);
//         cycle.push_back(cycle_start);
//         reverse(cycle.begin(), cycle.end());

//         cout << "Cycle found: ";
//         for (int v : cycle)
//             cout << v << " ";
//         cout << endl;
//     }
// }
// int main(){
//     int m;
//     cin >> n >> m;
//     for(int i = 0;i<m;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//         // adj[v].push_back(u);
//     }
//     find_cycle();
//     return 0;
// }
/**
 * 
 */
