#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll findpar(ll x,ll parent[]){
    return parent[x]= ( (parent[x] == x) ? x : findpar(parent[x],parent) ) ;
}
void Union(ll a,ll b,ll parent[]){
    a = findpar(a,parent);
    b = findpar(b,parent);
    parent[a] = b;
}
int main(){
    int n;
    cin >> n;
    ll parent[n+2];
    for(int i = 0;i<n+2;i++){
        parent[i] = i;
    }
    int q;
    cin >> q;
    while(q--){
        char ch;
        int t;
        cin >> ch >> t;
        if(ch == '?'){
            int r = findpar(t,parent);
            if(r == n+1)r = -1;
            cout << r << "\n";
        }
        else{
            Union(t,t+1,parent);
        }
    }
    return 0;
}