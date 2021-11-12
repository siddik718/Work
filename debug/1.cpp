#include<bits/stdc++.h>
using namespace std;
int main(){
    int v[130] = {0};
    for(int i = 0;i<3;i++){
        char ch;cin >> ch;
        v[ch] = 1;
    }
    for(int i = 0;i<=130;i++){
        if(v[i]!=0)cout << i << ' ';
    }
    return 0;
}