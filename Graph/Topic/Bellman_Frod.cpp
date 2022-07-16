/**
 * @file Bellman_Frod.cpp
 * @date 2022-07-15
 * It Finds shortest paths from a source vertex to all vertices in a graph.It Can detect negative weight cycles.
 */
#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int src;
    int dest;
    int weight;
};
vector<Edge> adj;
int node ,edges;

void BellMan_Frod(int src){
    vector<int> dist(node+1,INT_MAX);
    vector<int> parent(node+1,-1);
    dist[src] = 0;
    for(int i = 0;i<node-1;i++){
        int f = 1;
        for(auto it : adj){
            if(dist[it.src] + it.weight < dist[it.dest]){
                dist[it.dest] = dist[it.src] + it.weight;
                parent[it.dest] = it.src;
                f = 0;
            }
        }
        if(f) break;
    }
    for(auto it : adj){
        if(dist[it.src] + it.weight < dist[it.dest]){
            cout<<"Graph contains a negative weight cycle"<<endl;
            return;
        }
    }
    for(int i = 0;i<node;i++){
        cout<<"Distance from "<<src<<" to "<<i<<" is "<<dist[i]<<endl;
    }
}

int main(){
    cin >> node >> edges;
    

    for(int i = 0;i<edges;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj.push_back({u,v,w});
    }
    int source;
    cin >> source;

    BellMan_Frod(source);

    return 0;
}