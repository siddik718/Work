#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll N = 1e5+5;
const ll inf = 1e18;
vector <pair<ll,ll>> adj[N];
vector <ll> dist(N,inf),parents(N);
void Dijkstra(){
    priority_queue< pair<ll,ll> , vector <pair<ll,ll>> , greater <pair<ll,ll>> > pq;
    pq.push({0,1});
    dist[1] = 0;
    parents[1] = -1;
    while(!pq.empty()){
        ll a = pq.top().first;
        ll b = pq.top().second;
        pq.pop();
        for(auto it : adj[b]){
            ll x = it.first;
            ll y = it.second;
            if(dist[x] > dist[b] + y){
                dist[x] = dist[b] + y;
                pq.push({dist[x],x});
                parents[x] = b;
            }
        }
    }
}
int main()
{
    ll node,edge;
    cin >> node >> edge;
    for(ll i = 1;i<=edge;i++){
        ll u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    Dijkstra();
    if(dist[node] == inf){
        cout << -1 << '\n';
    }else{
        vector <ll> v;
        for(ll i = node;i != -1;i = parents[i])
        v.push_back(i);
        reverse(v.begin(),v.end());
        for(auto it : v)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}