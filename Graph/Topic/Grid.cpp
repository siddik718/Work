#include <bits/stdc++.h>
using namespace std;
int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dist[100][100],vis[100][100],cell[100][100];
int n,m;
bool isValid(int x,int y){
    if(x<1 || y<1 || x>n || y>m || vis[x][y])return false;
    return true;
}
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
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    //freopen("Input.txt","r",stdin);
    cin >> n >> m;
    bfs(1,1);
    return 0;
}





// // DFS:
// #include<bits/stdc++.h>
// using namespace std;
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
// int vis[1001][1001];
// char cell[1001][1001];
// int n,m;
// bool isvalid(int x,int y){
//     if(x<1 || x>n || y<1 || y> m 
//     || vis[x][y] || cell[x][y] == '#')return false;
//     return true;
// }
// void dfs(int x,int y){
//     vis[x][y] = 1;
//     for(int i = 0;i<4;i++){
//         int a = x+dx[i],b = y+dy[i];
//         if(isvalid(a,b))dfs(a,b);
//     }
// }
// int main()
// {
//     //freopen("Input.txt","r",stdin);
//     cin >> n >> m;
//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             cin >> cell[i][j];
//         }
//     }
//     int rooms = 0;
//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             if(!vis[i][j] && cell[i][j] != '#'){
//                 rooms++;
//                 dfs(i,j);
//             }
//         }
//     }
//     cout << rooms;
//     return 0;
// }