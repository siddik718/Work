#include <bits/stdc++.h>
using namespace std;
struct node{
    int u,v,wt;
    node(int first,int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<node>adj;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj.push_back(node(a,b,c));
    }
    return 0;
}
