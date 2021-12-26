#include<bits/stdc++.h>
#define ll long long int
#define FOR(i,n) for(int i = 0;i<(n);i++)
using namespace std;

// int dx[] = {0,0,-1,1,1,-1,-1,1};
// int dy[] = {1,-1,0,0,1,1,-1,-1};
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

string grid[55];
int vis[55][55],h,w,cnt;
bool isvalid(int a,int b){
     if(a < 0 || a >= h || b < 0 || b >= w || vis[a][b])return false;
    return true;
}
void dfs(int x,int y){
    vis[x][y] = 1;
    FOR(i,8){
        int a = x+dx[i],b = y+dy[i];
        if(isvalid(a,b) && (grid[a][b] == grid[x][y]+1) ){
            cnt++;dfs(a,b);
        }
    }
}
int main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int Case = 1;
    while(cin >> h >> w){
        if(h == 0 && w == 0)break;
        FOR(i,h){
            grid[i].clear();
        }
        memset(vis,0,sizeof(vis));
        FOR(i,h){
            cin >> grid[i];
        }
        int ans = 0;
        FOR(i,h){
            FOR(j,w){
                if(!vis[i][j] && grid[i][j] == 'A'){
                    cnt = 1;
                    dfs(i,j);
                    ans = max(ans,cnt);
                }
            }
        }
        cout << "Case " << Case++ << ": "<< ans << "\n";
    }
    return 0;
}