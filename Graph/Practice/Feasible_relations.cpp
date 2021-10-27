#include<bits/stdc++.h>
using namespace std;
vector <int> adj[1000005];
int vis[1000005],cc[1000005];
int cur;
void dfs(int src){
    vis[src] = 1;
    cc[src] = cur;
    for(auto u : adj[src]){
        if(!vis[u]){
            dfs(u);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("Practice.txt","r",stdin);
    #endif
    int test;cin >> test;
    while(test--){
        int n,k;cur = 0;cin >> n >> k;
        vector <pair<int,int>> v;
        for(int i = 1;i<=n;i++)
        adj[i].clear(),vis[i] = 0,cc[i] = 0;
        for(int i = 1;i<=k;i++){
            int a,b;
            string s;
            cin >> a >> s >> b;
            if(s == "="){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }else{
                v.push_back({a,b});
            }
        }
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                cur++;
                dfs(i);
            }
        }
        bool ok = true;
        for(int i = 0;i<v.size();i++){
            if(cc[v[i].first] == cc[v[i].second]){
                ok = false;break;
            }
        }
        ok ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}