#include<bits/stdc++.h>
using namespace std;
vector <long long> f(21);
void fact(){
    f[0] = 1;
    for(int i = 1;i<=20;i++){
        f[i] = f[i-1]*i;
    }
    for(int i = 0;i<=20;i++){
        cout << f[i] << " ";
        if(f[i] <= (long long)(1e12)){
            cout << "Yes ";
        }
    }
}
int main(){
    fact();
    return 0;
}