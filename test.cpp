#include <bits/stdc++.h>
using namespace std;
int main(){  
    cin.tie(0)->sync_with_stdio(0);
    freopen("test.in","r",stdin);
    auto solve = [&](){
        int n;
        string s;
        cin >> n >> s;
        int i = 0,ans = 0;
        while(i < n - 1){
            if(s[i] == '('){
                i+=2;
                ans++;
            }else{
                int j = i+1;
                while(j<n && s[j] == '(')j++;
                if(j == n)break;
                i = j+1;
                ans++;
            }
        }
        cout << ans << " " << n - i << endl;
    };
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}