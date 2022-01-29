#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    vector <int> coins{50,25,10,5,1};
    vector < vector <int> > dp(7,vector <int> (7500+5));
    dp[0][0] = 1;
    for(int i = 1;i<=5;i++){
        for(int j = 0;j<=7500;j++){
            int left = j-coins[i-1];
            dp[i][j] = dp[i-1][j];
            if(left>=0){
                dp[i][j] += dp[i][left];
            }
        }
    }
    while(cin >> N){
        cout << dp[5][N] << endl;
    }
    return 0;
}