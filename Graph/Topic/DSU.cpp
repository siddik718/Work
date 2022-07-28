#include<bits/stdc++.h>
using namespace std;
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
    int m;
    cin>>m;
    vector<int>parent(m+1);
    for(int i = 0;i<=m;i++){
        parent[i]=i;
    }
    vector<int>rank(m+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        Union(a,b,parent,rank);
    }
    if(FindPar(2,parent) == FindPar(3,parent))
        cout<<"Same\n";
    else
        cout<<"Different\n";
    return 0;
}