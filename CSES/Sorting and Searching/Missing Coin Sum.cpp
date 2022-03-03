#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int &i : a)cin >> i;
    sort(a.begin(),a.end());
    int sum = 0,ans = 1;
    for(int i : a){
        if(i<=ans)ans+=i;
    }
    cout << ans << endl;
    return 0;
}