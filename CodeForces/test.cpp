#include<bits/stdc++.h>
#define FOR(i,n) for(int i = 0;i<(n);i++)
using namespace std;
using ll = long long int;
const double inf = 2*1e18;
double C;
double good(double x){
    return x*x + sqrt(x) >= C;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> C;
    double l = 0.0,r = inf;
    FOR(i,150){
        double m = l + (r - l)/2;
        if(good(m))r = m;
        else l = m;
    }
    cout << setprecision(20) << l;
    return 0;
}