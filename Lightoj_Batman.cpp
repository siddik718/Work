#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b,string c){
    int n = a.size(),m = b.size(),p = c.size();
    int dp[n+1][m+1][p+1];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            for(int k = 0;k<=p;k++){
                if(i == 0 || j == 0 || k == 0){
                    dp[i][j][k] = 0;
                }else if(a[i-1] == b[j-1] && a[i-1] == c[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                }else{
                    dp[i][j][k] = max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                }
            }
        }
    }
    return dp[n][m][p];
}
int main(){
    int test;cin >> test;
    for(int i = 1;i<=test;i++){
        string a,b,c;
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        cout << lcs(a,b,c) << endl;
    }
    return 0;
}