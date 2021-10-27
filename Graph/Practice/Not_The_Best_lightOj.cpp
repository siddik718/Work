/**
 * @file Not_The_Best_lightOj.cpp
 * Fuck This Problem 🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬🤬
 */
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll N = 1e5+2;
const ll inf = 1e18;
vector <pair<ll,ll>> adj[N];
int n,m;
void Dijkstra(){
    vector <vector <ll> > dist(n+1,vector<ll> (n+1,inf));
    priority_queue< pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
    pq.push({0,1});
    dist[1][0] = 0;
    while(!pq.empty()){
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if(dist[u][n-1] < d)continue;
        vector <pair<ll,ll>> v = adj[u];
        for(int i = 0;i<v.size();i++){
            ll dest = v[i].first;
            ll cost = v[i].second;
            if(d + cost < dist[dest][n-1]){
                dist[dest][n-1] = d+cost;
                sort(dist[dest].begin(),dist[dest].end());
                pq.push({d + cost,dest});
            }
        }
    }
    for(int i =0;i<n;i++){
        cout << dist[n][i] << " \n"[i+1 == n];
    }
    for(int i = 1;i<n;i++){
        if(dist[n][i] > dist[n][0]){
            cout << dist[n][i] << '\n';
            return;
        }
    }
    cout << dist[n][n-1] << '\n';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Practice.txt","r",stdin);
    freopen("ppractice.txt","w",stdout);
    #endif
    ll test;cin >> test;
    for(ll Case = 1;Case<=test;Case++){
        cin >> n >> m;
        for(int i = 1;i<=n;i++){
            adj[i].clear();
        }
        for(int i = 1;i<=m;i++){
            ll u,v,w;cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        cout << "Case " << Case << ": ";
        Dijkstra();
    }
    return 0;
}