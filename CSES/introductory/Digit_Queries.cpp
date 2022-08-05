#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {

    int q = 1;
    
    vector <ll> PO10(13,1);
    for (int i = 1; i < 13; i++) {
        PO10[i] = PO10[i - 1] * 10;
    }

    while (q--) {
        ll k;
        cin >> k;
        ll digit = 0;
        ll no_of_digit = 0;
        ll prev_digit = 0;
        for (int i = 1; i < 13; i++) {
            digit += ( (PO10[i] - PO10[i-1]) * i);
            if(digit >= k) {
                no_of_digit = i;
                break;
            }
            prev_digit = digit;
        }
        // cout << sum << "\n";
        ll l = PO10[no_of_digit - 1] , r = PO10[no_of_digit]-1;
        // cout << l << " " << r << '\n';
        ll val = 0,val_index = 0;
        while(l<=r){
            ll m = (l+r)/2;
            ll index = prev_digit + 1 + (m - PO10[no_of_digit-1]) * no_of_digit;
            if(index <= k){
                if(m > val){
                    val = m;
                    val_index = index;
                }
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        // cout << val << " " << val_index << '\n';
        string str = to_string(val);
        cout << str[k - val_index] << '\n';
    }

    return 0;
}