#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,wt;
    edge(int first,int second,int weight){
        u = first;
        v = second;
        wt = weight;
    }
};
bool cmp(edge a,edge b){
    return a.wt < b.wt;
}
int FindPar(int v,vector<int>&parent){
    if(parent[v]==v)
        return v;
    return parent[v] = FindPar(parent[v],parent);
}
void Union(int a,int b,vector<int>&parent,vector<int>&rank){
    int x=FindPar(a,parent);
    int y=FindPar(b,parent);
    if(x==y) return;
    if(rank[x]>rank[y]){
        parent[y]=x;
    }
    else{
        parent[x]=y;
        if(rank[x]==rank[y]) rank[y]++;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<edge> edges;
    for(int i = 0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back(edge(u,v,wt));
    }
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n+1),rank(n+1,0);
    for(int i = 0;i<=n;i++){
        parent[i] = i;
    }
    int cost = 0;
    vector<pair<int,int>> mst;
    for(auto [u,v,wt] : edges){
        if(FindPar(u,parent) != FindPar(v,parent)){
            Union(u,v,parent,rank);
            mst.push_back({u,v});
            cost += wt;
        }
    }
    cout << cost << endl;
    for(auto [u,v] : mst){
        cout << u << " " << v << endl;
    }
    return 0;
}

