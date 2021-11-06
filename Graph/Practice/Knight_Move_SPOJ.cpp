#include <bits/stdc++.h>
using namespace std;
int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dist[1001][1001],vis[1001][1001],cell[1001][1001];
bool isValid(int x,int y){
    if(x<1 || y<1 || x>1000 || y>1000 || vis[x][y])return false;
    return true;
}
int n,m;
void bfs(int x,int y){
    vis[x][y] = 1;
    dist[x][y] = 0;
    queue <pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto top = q.front();q.pop();
        for(int i = 0;i<8;i++){
            int x = top.first+dx[i];
            int y = top.second+dy[i];
            if(isValid(x,y)){
                vis[x][y] = 1;
                dist[x][y] = dist[top.first][top.second]+1;
                q.push({x,y});
            }
        }
    }
}
int main()
{
   // freopen("Practice.txt","r",stdin);
    bfs(1,1);
    int t;cin >> t;
    while(t--){
        cin >> n >> m;
        cout << dist[n][m] << '\n';
    }
    return 0;
}
