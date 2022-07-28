#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll findpar(ll x,ll parent[]){
    return parent[x]= ( (parent[x] == x) ? x : findpar(parent[x],parent) ) ;
}
void Union(ll a,ll b,ll parent[],ll rank[]){
    a = findpar(a,parent);
    b = findpar(b,parent);
    if(a == b)return;
    if(rank[a] == rank[b]){
        rank[a]++;
    }
    if(rank[a] > rank[b]){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}
int main(){
    int n;
    cin >> n;
    ll parent[n],rank[n];
    for(int i = 0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        Union(a,b,parent,rank);
    }
    for(int i = 0;i<n;i++){
        cout << findpar(i,parent) << " \n"[i==n-1];
    }
    return 0;
}