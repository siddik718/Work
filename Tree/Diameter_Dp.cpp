#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
vector<int>adj[N];
int n,d,d1[N],d2[N]; 

void print(){
    for(int i = 1;i<=n;i++)cout<<d1[i]<<" \n"[i==n];
    for(int i = 1;i<=n;i++)cout<<d2[i]<<" \n"[i==n];
}
// find the diameter of the tree using DP.
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
    }
    d=max(d,d1[u]+d2[u]);
    // print();cout<<d<<'\n';
}
int main(){
    // freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout<<d<<'\n';
    return 0;
}
