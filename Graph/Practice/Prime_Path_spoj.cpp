#include <bits/stdc++.h>
using namespace std;
vector <int> adj[10005];
int  vis[10005];
int dist[10005];
bool Isprime(int x){
    for(int i = 2;i*i<=x;i++){
        if(x%i == 0)return false;
    }
    return true;
}
bool isValid(int a,int b){
    int cnt = 0;
    while(a){
        if(a%10 != b%10)cnt++;
        a /= 10;b /= 10;
    }
    return cnt == 1;
}
void buildGraph(){
    vector <int> v;
    for(int i = 1000;i<=9999;i++){
        if(Isprime(i))
            v.push_back(i);
    }
    for(int i = 0;i<=v.size();i++){
        for(int j = i+1;j<=v.size();j++){
            int x = v[i],y = v[j];
            if(isValid(x,y)){
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }
    }
}
void bfs(int src){
    vis[src] = 1;
    dist[src] = 0;
    queue <int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Practice.txt","r",stdin);
    #endif
    int test;cin >> test;
    buildGraph();
    while(test--){
        int a,b;cin >> a >> b;
        for(int i =1000;i<=9999;i++)dist[i] = -1,vis[i] = 0;
        bfs(a);
        if(dist[b] == -1)
            cout << "Impossible\n";
        else
            cout << dist[b] << '\n';
    }
    return 0;
}