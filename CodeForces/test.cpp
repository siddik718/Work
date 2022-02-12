#include<bits/stdc++.h>
using namespace std;
pair<int,int> binary(vector <pair<int,int>> a,int val){
    int l = 0,r = a.size()-1,mid;
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid].first == val){
            return {mid,a[mid].second};
        }
        else if(a[mid].first < val){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return {-1,-1};
}
int main(){
    vector <pair <int,int> > v;
    v.push_back({6,0});
    v.push_back({4,1});
    v.push_back({2,2});
    sort(v.begin(),v.end());
    cout << v.size() << endl;
    auto x = binary(v,2);
    cout << x.first << " " << x.second << endl;
    x = binary(v,4);
    cout << x.first << " " << x.second << endl;
    x = binary(v,6);
    cout << x.first << " " << x.second << endl;
    return 0;
}