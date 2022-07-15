#include<iostream>
#include<vector>
using namespace std;
const int MaxN = 2e5 + 10;
vector<int> tree[MaxN];
vector<int> no_subtree(MaxN, 0);
void dfs(int root,int parent){
    int sub_tree = 0;
    for(auto child : tree[root]){
        if(child == parent)continue;
        dfs(child, root);
        sub_tree += (1 + no_subtree[child]);
    }
    no_subtree[root] = sub_tree;
}
int main(){
    int node;
    cin >> node;
    for(int i = 2; i <= node; i++){
        int a;cin >> a;
        tree[a].push_back(i);
    }
    dfs(1,0);
    for(int i = 1; i <= node; i++){
        cout << no_subtree[i] << " \n"[i == node];
    }
    return 0;
}