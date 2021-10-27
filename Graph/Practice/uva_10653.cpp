#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n,m,q;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int vis[N][N],dist[N][N];
bool isvalid(int x,int y){
    if(x<0 || x >= n || y<0 || y>= m || vis[x][y])return false;
    return true;
}
void bfs(int srcx,int srcy){
    vis[srcx][srcy] = 1;
    dist[srcx][srcy] = 0;
    queue<pair<int,int>> q;
    q.push({srcx,srcy});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int d = dist[x][y];
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isvalid(nx,ny)){
                q.push({nx,ny});
                vis[nx][nx] = 1;
                dist[nx][nx] = d + 1;
            }
        }
    }
}
int main()
{
    freopen("Practice.txt","r",stdin);
    while(cin >> n >> m, n ){
        memset(vis,0,sizeof(vis));
        memset(dist,0,sizeof(dist));
        cin >> q;
        while(q--){
            int row,col,x;
            cin >> row >> col;
            for(int i = 0;i<col;i++){
                cin >> x;
                vis[row][x] = 1;
            }
        }
        int startx,starty,endx,endy;
        cin >> startx >> starty;
        cin >> endx >> endy;
        bfs(startx,starty);
        cout << dist[endx][endy] << '\n';
    }
    return 0;
}