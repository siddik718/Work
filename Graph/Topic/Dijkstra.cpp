/**
 * Dijkstra.cpp
 * author Abu Bakar Siddik
 * In this Algorithm we need to use priorty queue to keep 
 * the minimum dist at top .
 */
#include<bits/stdc++.h>
using namespace std;
vector <pair<int,int>> adj[1000];
int dist[10000];
int node,edge;
void Dijkstra(int src){
    priority_queue< pair<int,int> , vector <pair<int,int>> , greater <pair<int,int>> > pq;
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()){
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        for(auto it : adj[b]){
            int x = it.first;
            int y = it.second;
            if(dist[x] > dist[b] + y){
                dist[x] = dist[b] + y;
                pq.push({dist[x],x});
            }
        }
    }
}
int main()
{
    freopen("Input.txt","r",stdin);
    cin >> node >> edge;
    for(int i = 1;i<=node;i++){
        adj[i].clear();dist[i] = INT_MAX;
    }
    for(int i = 1;i<=edge;i++){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;cin >> src;
    Dijkstra(src);
    for(int i = 1;i<=node;i++){
        cout << "Distace Between Source " << src << " To " << i << " Node Is : ";
        cout << dist[i] << "\n";
    }
    return 0;
}



















