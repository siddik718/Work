#include<bits/stdc++.h>
using namespace std;
int m;
int parent[10000];
int Rank[10000];
void makeset(){
    for(int i = 0;i<=m;i++){
        parent[i] = i;
        Rank[i] = 0;
    }
}
int findpar(int n){
    if(n == parent[n])return n;
    return parent[n] = findpar(parent[n]);
}
void Union(int u,int v){
    u = findpar(u);v =findpar(v);
    if(Rank[u] < Rank[v]){
        parent[u] = v;
    }else if(Rank[v] < Rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        Rank[u]++;
    }
}
int main(){
    makeset();
    return 0;
}