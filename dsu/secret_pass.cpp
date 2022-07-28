#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> parent(27);
vector <int> Rank(27);
ll Get(ll x){
    return parent[x] = (parent[x]==x?x:Get(parent[x]));
}
void Union(ll a,ll b){
    a = Get(a);
    b = Get(b);
    if(Rank[a] == Rank[b])Rank[a]++;
    if(Rank[a] > Rank[b])parent[b] = a;
    else parent[a] = b;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i<27;i++){
        parent[i] = i;
        Rank[i] = 1;
    }
    vector <bool> vis(27,false);
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        vector <bool> tmp(27,false);
        for(char ch : str){
            tmp[ch-'a'] = true;
        }
        for(int j = 0;j<27;j++){
            if(tmp[j] == true){
                vis[j] = true;
                Union(str[0]-'a',j);
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i<27;i++){
        if(vis[i] == true && Get(i) == i)ans++;
    }
    cout << ans << endl;
    return 0;
}