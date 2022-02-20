#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    sort(a.begin(),a.end());
    for(auto i : a)cout << i << " " ;cout << endl;
    return 0;
}