#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int large(int a[],int n){
    // unordered_map<int,int> index;
    map<int,int> index;
    int ans = 0,j = 0;
    rep(i,n){
        j = max(index[a[i]],j);
        ans = max(ans,i-j+1);
        cout << i << " " << j << " " << ans << "\n";
        index[a[i]] = i+1;
    }
    return ans;
}
int main(){
    int n;cin >> n;
    int a[n];
    rep(i,n)cin >> a[i];
    cout << large(a,n) << endl;
    return 0;
}