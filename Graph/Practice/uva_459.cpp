#include<bits/stdc++.h>
using namespace std;
vector <int> adj[27];
int vis[27];
void dfs(int n){
    vis[n] = 1;
    for(auto it : adj[n]){
        if(!vis[it])dfs(it);
    }
}
int main(){
    int test;cin >> test;
    while(test--){
        char ch;
        int n;
        cin >> ch;
        n = ch - 64;
        cin.ignore();
        for(int i = 0;i<=n;i++)adj[i].clear(),vis[i] = 0;
        string a;
        while(getline(cin,a) && a != ""){
            adj[a[0] - 64].push_back(a[1] - 64);
            adj[a[1] - 64].push_back(a[0] - 64);
        }
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i);
            }
        }
        cout << cnt << '\n';
        if(test)cout << '\n';
    }
    return 0;
}