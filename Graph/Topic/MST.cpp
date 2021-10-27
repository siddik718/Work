/** Prims:
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("Input.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    vector <pair<int,int>> adj[n];
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector <int> key(n,INT_MAX);
    vector <int> parent(n,-1);
    vector <bool> mst(n,false);
    key[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    for(int cnt = 0; cnt < n-1;cnt++){
        // int mini = INT_MAX,u;
        // for(int v = 0;v<n;v++){
        //     if(!mst[v] && key[v] < mini){
        //         mini = key[v],u = v;
        //     }
        // }
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        for(auto it : adj[u]){
            int v = it.first;
            int weight = it.second;
            if(!mst[v] && (weight < key[v])){
                parent[v] = u,key[v] = weight;
                pq.push({key[v],v});
            }
        }
    }
    for(int i= 0;i<n;i++){
        cout << parent[i] << " - " << i << '\n';
    }
    return 0;
}
**/
// Kruskal's :
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     freopen("Input.txt","r",stdin);
//     int n,m;
//     cin >> n >> m;
//     vector <pair<int,int>> adj[n];
//     for(int i = 0;i<m;i++){
//         int u,v,w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }
//     return 0;
// }'


// #include<bits/stdc++.h>
// using namespace std;
// const int inf = 1e12;
// int main(){
//     freopen("Input.txt","r",stdin);
//     int n,m;
//     cin >> n >> m;
//     vector <pair<int,int>> adj[n];
//     for(int i = 0;i<m;i++){
//         int u,v,w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }
//     vector <int> parents(n,-1),key(n,inf),MST(n,0);
//     key[0] = 0;
//     priority_queue<pair<int,int>,vector <pair<int,int>> , greater <pair<int,int>> > pq;
//     pq.push({0,0}); 
//     for(int i = 0;i<n-1;i++){
//         int u = pq.top().second;
//         pq.pop();
//         MST[u] = 1;
//         for(auto it : adj[u]){
//             int v = it.first;
//             int weight = it.second;
//             if(!MST[v] && weight<key[v]){
//                 pq.push({key[v],v});
//                 parents[v] = u;
//                 key[v] = weight;
//             }
//         }
//     }
//     return 0;
// }