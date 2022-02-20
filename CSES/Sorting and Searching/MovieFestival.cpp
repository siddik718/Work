#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    vector <pair<int,int> > v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),[&](auto x,auto y){
        return x.second < y.second;
    });
    int movies = 0,end_stat = 0;
    for(int i = 0;i<n;i++){
        if(v[i].first >= end_stat){
            end_stat = v[i].second;
            movies++;
        }
    }
    cout << movies << endl;
    return 0;
}