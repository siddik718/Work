#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int vis[10][10];
int dist[10][10];
string a,b;
bool isvalid(int x,int y){
    if(x <= 0 || x > 8 || y <= 0 || y > 8 || vis[x][y])return false;
    return true;
}
void bfs(int x1,int y1,int x2,int y2){
    queue <pair<int,int>> q;
    memset(vis,0,sizeof vis);
    q.push({x1,y1});
    vis[x1][y1] = 1;
    dist[x1][y1] = 0;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        if(top.first == x2 && top.second == y2){
            cout << "To get from " << a << " to " << b << " takes " << dist[x2][y2] << " knight moves.\n";
            return;
        }
        rep(i,8){
            int x = top.first+dx[i];
            int y = top.second+dy[i];
            if(isvalid(x,y)){
                vis[x][y] = 1;
                q.push({x,y});
                dist[x][y] = dist[top.first][top.second] + 1;
            }
        }
    }
}
int main(){
    while(cin >> a >> b){
        int x1 = a[0] - 'a' + 1;
        int y1 = a[1] - '0';
        int x2 = b[0] - 'a' + 1;
        int y2 = b[1] - '0';
        bfs(x1,y1,x2,y2);
    }
    return 0;
}