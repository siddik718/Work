#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
#define rep(i,n) for(int i = 0;i<n;i++)
vector<int>weight,value;
vector<vector<ll>>dp; 
int n,w;
ll func(int i,int j){
    if(i == 0 || j == 0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    ll tet = func(i-1,j);
    ll left = j - weight[i-1];
    if(left>=0){
        tet = max(tet,func(i-1,left)+value[i-1]);
    }
    return dp[i][j] = tet;
}
int main(){
    cin >> n >> w;
    weight.resize(n);value.resize(n);
    rep(i,n)cin >> weight[i] >> value[i];
    dp.resize(n+1,vector<ll>(w+1,-1));
    cout << func(n,w) << endl;
    return 0;
}

