#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+2;
vector <int> adj[maxN];
int fun(int vertex,int par,int isGuard,vector<vector<int>>&dp){
    if(adj[vertex].size()==0)
        return 0;
    if(dp[vertex][isGuard]!=-1) return dp[vertex][isGuard];
    int tot = 0;
    for(auto i : adj[vertex]){
        if(i == par)continue;
        if(isGuard){
            tot += min(fun(i,vertex,0,dp),fun(i,vertex,1,dp));
        }else{
            tot +=  fun(i,vertex,1,dp);
        }
    }
    return dp[vertex][isGuard] = tot+isGuard;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    cout << min(fun(1,0,1,dp),fun(1,0,0,dp)) << endl;
    return 0;
}