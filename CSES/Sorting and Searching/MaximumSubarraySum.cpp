#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;cin >> n;
    vector <ll> a(n);
    for(ll &i : a)cin >> i;
    ll max_sum = a[0],sum = a[0];
    for(int i = 1;i<n;i++){
        sum = max(sum+a[i],a[i]);
        max_sum = max(sum,max_sum);
    }
    cout << max_sum << endl;
    return 0;
}