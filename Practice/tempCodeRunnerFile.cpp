#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
const ll inf = 1e18+7;
int main(){
    int t;cin >> t;
    for(int i = 1;i<=t;i++){
        int n;cin >> n;
        vector<ll> a(n);
        int flag = 0;
        for(auto &i : a){
            cin >> i;
            if(i >= 0) flag = 1;
        }
        cout << "Case " << i << ": ";
        if(flag == 0){
            ll mx = -inf;
            for(auto &i : a){
                mx = max(mx,i);
            }
            cout << mx << ' ' << 0 << '\n';
        }else{
            ll sum = 0;
            for(auto &i : a){
                if(i > 0) sum += i;
            }
            ll move = 0;
            flag = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] < 0){
                    flag = 1;
                }else{
                    if(flag == 1){
                        move++;
                    }
                    flag = 0;
                }
            }
            if(flag == 1)move++;
            if(a[0] < 0){
                move--;
            }
            if(a[n-1] < 0){
                move--;
            }
            cout << sum << ' ' << move << '\n';
        }

    }
    return 0;
}