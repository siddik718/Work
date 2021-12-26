#include<bits/stdc++.h>
using namespace std;
int n,m,source_x,source_y,des_x,des_y;
char cell[1005][1005],tmp[1005][1005];
int vis[1005][1005];
bool isvalid(int x,int y){
    if(x<1 || x > n || y < 1 || y > m || vis[x][y] || cell[x][y] == '#')
        return false;
    return true;
}
void bfs(int x,int y){
    queue <pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    string path = "";
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int dx = p.first;
        int dy = p.second;
        if(cell[dx][dy] == 'B'){
            cout << "YES\n";
            string ans;
            while(true){
                if(dx == x && dy == y)break;
                ans.push_back(tmp[dx][dy]);
                if(ans.back() == 'L')dy++;
                if(ans.back() == 'R')dy--;
                if(ans.back() == 'U')dx++;
                if(ans.back() == 'D')dx--;
            }
            reverse(ans.begin(),ans.end());
            cout << ans.size() << '\n' << ans << '\n';
            return;
        }
        if(isvalid(dx,dy-1)){ // left
            tmp[dx][dy-1] = 'L';
            q.push({dx,dy-1});
            vis[dx][dy-1] = 1;
        }
        if(isvalid(dx,dy+1)){ // right
            tmp[dx][dy+1] = 'R';
            q.push({dx,dy+1});
            vis[dx][dy+1] = 1;
        }
        if(isvalid(dx-1,dy)){ // up
            tmp[dx-1][dy] = 'U';
            q.push({dx-1,dy});
            vis[dx-1][dy] = 1;
        }
        if(isvalid(dx+1,dy)){ // down
            tmp[dx+1][dy] = 'D';
            q.push({dx+1,dy});
            vis[dx+1][dy] = 1;
        }
    }
    cout << "NO\n";
}
int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> cell[i][j];
            if(cell[i][j] == 'A'){
                source_x = i;
                source_y = j;
            }
            if(cell[i][j] == 'B'){
                des_x = i;
                des_y = j;
            }
        }
    }
    bfs(source_x,source_y);
    return 0;
}