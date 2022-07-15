#include<iostream>
#include<vector>
using namespace std;
const int MaxN = 2e5 + 10;
vector<int> tree[MaxN];
bool done[MaxN];
int ans;
void dfs(int root,int parent){
    for(auto child : tree[root]){
        if(child == parent)continue;
        dfs(child, root);
        if(!done[child] && !done[root]){
            ans++;
            done[child] = done[root] =true;
        }
    }
}
int main(){
    int node;
    cin >> node;

    for(int i = 1; i <= node-1; i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    cout << ans << '\n';
    return 0;
}