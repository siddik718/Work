#include<bits/stdc++.h>
#define FOR(i,n) for(int i = 1;i<=(n);i++)
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m,s_x,s_y;
char cell[1001][1001];
int vis[1001][1001];
bool isvalid(int x,int y){
    if(x<1 || x>n || y<1 || y>m || vis[x][y] || cell[x][y] == '#' )
        return false;
    return true;
}
void bfs(int x,int y){
    queue < pair <int,int> > q;
    q.push({x,y});
    vis[x][y] = 1;
    string ans = "";
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        if(nx == 1 || nx == n || ny == 1 || ny == m){
                    cout << "YES\n";
                    cout << ans.size() << "\n";
                    cout << ans << "\n";
                    return;
                }
        for(int i = 0;i<4;i++){
            int a = dx[i]+nx , b = dy[i]+ny;
            if(isvalid(a,b)){
                if(cell[a][b] == 'M' && cell[nx][ny] != 'A'){
                    cout << a << " " << b << " = " << nx << " " << ny << "\n";
                    cout << cell[a][b] << cell[nx][ny] << "\n";
                    cout << "NO\n";
                    return;
                }
                if(dx[i] == 0){
                    if(dy[i] == 1){
                        ans += 'R';
                    }else{
                        ans += 'L';
                    }
                }else if(dy[i] == 0){
                    if(dx[i] == 1){
                        ans += 'D';
                    }else{
                        ans += 'U';
                    }
                }
                vis[a][b] = 1;
                q.push({a,b});
                if(a == 1 || a == n || b == 1 || b == m){
                    cout << "YES\n";
                    cout << ans.size() << "\n";
                    cout << ans << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
int main(){
    cin >> n >> m;
    FOR(i,n){
        FOR(j,m){
            cin >> cell[i][j];
            if(cell[i][j] == 'A'){
                s_x = i;
                s_y = j;
            }
        }
    }
    bfs(s_x,s_y);
    return 0;
}