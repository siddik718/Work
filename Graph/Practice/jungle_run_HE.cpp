#include<bits/stdc++.h>
using namespace std;
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0, -1};
char cell[35][35];
int dist[35][35],vis[35][35];
int n;
bool isvalid(int x,int y){
    if(x > n || x < 1 || y > n || y < 1 || vis[x][y] || cell[x][y] == 'T')return false;
    return true;
}
void bfs(int sx,int sy){
    queue <pair<int,int>> q;
    q.push({sx,sy});
    dist[sx][sy] = 0;
    vis[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int d = dist[x][y];
        q.pop();
        for(int i =0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isvalid(nx,ny)){
                dist[nx][ny] = d+1;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}
int main()
{
    cin >> n;
    int sx = 1,sy = 1,ex = 1,ey = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> cell[i][j];
            if(cell[i][j] == 'S'){sx = i;sy = j;}
            if(cell[i][j] == 'E'){ex = i;ey = j;}
        }
    }
    bfs(sx,sy);
    cout << dist[ex][ey];
    return 0;
}