// Notice N is small.(N<=20).
#include<iostream>
#include<cmath>
using ll = long long;
int main(){
    int n;
    std::cin >> n;
    int a[n];
    for(int i = 0;i<n;i++){
        std::cin >> a[i];
    }
    ll ans = INT64_MAX;
    for(int i = 0;i<(1<<n);i++){
        ll left = 0,right = 0;
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                left += a[j];
            }else{
                right += a[j];
            }
        }
        ans = std::min(ans,std::abs(left-right));
    }
    std::cout << ans << std::endl;
    return 0;
}