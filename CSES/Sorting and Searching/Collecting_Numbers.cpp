#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    int pos[n+1];
    for(int i = 1;i<=n;i++){
        int x;cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for(int i = 2;i<=n;i++){
        if(pos[i]<pos[i-1])ans++;
    }
    cout << ans << endl;
    return 0;
}
/*
5
4 2 1 5 3
(1,3) (2,2) (3,5) (4,1) (5,4)
 */