#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int,int>;
const int MaxN = 2e5 + 10;
vector<int> tree[MaxN];
P bfs(int source){
    queue<P>q;
    q.push({source,0});
    vector<bool>used(MaxN,false);
    used[source] = true;
    P u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        used[u.first] = true;
        for(auto v : tree[u.first]){
            if(!used[v]){
                q.push({v,u.second+1});
            }
        }
    }
    return u;
}
int main(){
    int node;
    cin >> node;
    for(int i = 1; i <= node-1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    auto u = bfs(1);
    cout << bfs(u.first).second << '\n';
    return 0;
}