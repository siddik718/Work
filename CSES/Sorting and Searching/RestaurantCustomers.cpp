/*
 * RestaurantCustomers.cpp
 * we're given n intervals with distinct start and end points,
 * and we want to find the maximum number of intervals overlapping at some point.
 */
#include<bits/stdc++.h>
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <pair<int,int>> v;
    for(int i = 0;i<n;i++){
       int x,y;
       cin >> x >> y;
       v.push_back({x,1});
       v.push_back({y,-1});
    }
    sort(all(v));
    int ans = 0,sum = 0;
    for(auto i : v){
        sum+=i.S;
        ans = max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}