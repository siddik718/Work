/***
 * Bismillahir Rahmanir Rahim
 * Author:  Abu Bakar Siddik(City University-53 Batch , Dhaka)
 ***/
#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define FOR(i,n) for(int i = 0;i<(n);i++)

using ll = long long int;
using namespace std;
int Lower_Bound(vector<pair<int,int>> a,int x){
    int l = 0,r = a.size()-1;
    while(l < r){
        int m = l+(r-l)/2;
        if(x<=a[m].first){
            r = m;
        }else{
            l = m+1;
        }
    }
    if(l < a.size()-1 && a[l].first < x)l++;
    return l;
}
void solve(){
    int n,q;cin >> n >> q;
    vector <pair<int,int>> a;
    map <int,int> mp;
    for(int i = 0,x;i<n;i++){
        cin >> x;
        mp[x]++;
        a.push_back({x,(i+1)});
    }
    sort(a.begin(),a.end());
    while(q--){
        int x,k;cin >> x >> k;
        if(mp[x] < k){
            cout << -1 << endl;
        }else{
            k--;
            int i = Lower_Bound(a,x);
            cout << a[i+k].second << endl;
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("atcoderI.txt", "r", stdin);
    #endif
    solve();
    return 0;
}
