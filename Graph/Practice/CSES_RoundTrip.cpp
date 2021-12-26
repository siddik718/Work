#include<bits/stdc++.h>
#define FOR(i,n) for(int i = 0;i < (n) ; i++)
using namespace std;
int n,m,cycle_start,cycle_end;
vector <int> adj[100005],parent,color;
bool dfs(int v){
    color[v] = 1;
    for(auto u : adj[v]){
        if(color[u] == 0){
            parent[u] = v;
            if(dfs(u))return true;
        }else if(color[u] == 1){
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}
void find_cycle(){
    color.assign(n,0);
    parent.assign(n,-1);
    cycle_start = -1;
    FOR(v,n){
        if(color[v] == 0 && dfs(v))break;
    }
    if(cycle_start == -1){
        cout << "IMPOSSIBLE\n";
    }else{
        vector <int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(),cycle.end());
        cout << cycle.size() << "\n";
        for(auto it : cycle)cout << it+1 << " ";
        cout << '\n';
    }

}
int main(){
    cin >> n >> m;
    FOR(i,m){
        int a,b;cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
    }
    find_cycle();
    return 0;
}