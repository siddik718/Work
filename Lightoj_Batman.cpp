#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b,string c){
    int n = a.size(),m = b.size(),p = c.size();
    vector <vector <vector<int> >> dp (n+1,vector<vector<int>>(m+1,vector<int>(p+1)));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int k = 1;k<=p;k++){
                if(a[i-1] == b[j-1] && a[i-1] == c[k-1]){
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
        cout << "Case " << i << ": " << lcs(a,b,c) << endl;
    }
    return 0;
}