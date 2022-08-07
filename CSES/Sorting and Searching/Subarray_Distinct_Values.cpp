#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
map <ll,ll> cnt;
ll num;
void add(int x){
    cnt[x]++;
    if(cnt[x] == 1)num++;
}
void remove(int x){
    cnt[x]--;
    if(cnt[x] == 0)num--;
}
int k;
bool good(){
    return num <= k;
}
int main () {
    int n;
    cin >> n >> k;
    vector <int> x(n);
    for(auto &i : x) cin >> i;
 
    ll ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        add(x[r]);
        while(!good()){
            remove(x[l]);
            l++;
        }
        ans += (r - l + 1);
    }
 
    cout << ans ;
 
    return 0;
}