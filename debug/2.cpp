#include<bits/stdc++.h>
#define rep(i,a,n) for(int i = (a) ; i < (n) ; i++)
using namespace std;
using ll = long long int;
const int MAX = 1000;
int grid[MAX+5][MAX+5];
int pfix[MAX+5][MAX+5];
int main(){
    ll n,q;cin >> n >> q;
    rep(i,0,n){
        rep(j,0,n){
            char ch;cin >> ch;
            grid[i+1][j+1] += (ch == '*'); 
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            pfix[i][j] = grid[i][j]+pfix[i-1][j]+pfix[i][j-1]-pfix[i-1][j-1];
        }
    }
    while(q--){
        ll x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pfix[x2][y2]-pfix[x1-1][y2]-pfix[x2][y1-1]+pfix[x1-1][y1-1]<<"\n";
    }
    return 0;
}