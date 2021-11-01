#include<bits/stdc++.h>
using namespace std;
int dx[] = {-1,-1,0,0,1,1};
int dy[] = {-1,0,-1,1,0,1};
int grid[205][205],n;
void takeinput(int n){
    for(int i = 0;i<n;i++){
        string a;cin >> a;
        for(int j = 0;j<n;j++){
            if(a[j] == 'w') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
}
bool isvalid(int x,int y){
    if(x<0 || x>= n || y < 0 || y >= n ||  grid[x][y] != 1)
        return false;
    return true;
}
bool W;
void dfs(int src_x,int src_y){
    grid[src_x][src_y] = -1;
    if(src_y == n-1){
        W = true;
        return;
    }
    for(int i = 0;i<6;i++){
        int x = dx[i]+src_x;
        int y = dy[i]+src_y;
        if(isvalid(x,y)){
            dfs(x,y);
        }
    }
}
int main(){
    freopen("Practice.txt","r",stdin);
    int test = 1;
    while(cin >> n,n){
        W = false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                grid[i][j] = 0;
            }
        }
        takeinput(n);
        for(int i = 0;i<n;i++){
            if(grid[i][1] == 1)dfs(i,1);
        }
        cout << test++ << " ";
        if(W)cout << "W\n";
        else cout << "B\n";
    }
    return 0;
}