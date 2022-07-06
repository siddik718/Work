#include<bits/stdc++.h>
using namespace std;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
char cell[55][55];
int dis[55][55];
int h,w;
bool isvalid(int x,int y){
    return (x>=0 && x<h && y>=0 && y<w);
}
void dfs(int i,int j,int dest){
    for(int i = 0;i<8;i++){
        dis[i][j] = dest + 1;
        int x = i+dx[i];
        int y = j+dy[i];
        if(isvalid(x,y) && cell[i][j] == cell[x][y]+1 && dis[x][y] < dis[i][j] + 1){
            dfs(x,y,dis[i][j]);
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    while(cin>>h>>w){
        if(h==0&&w==0)break;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>cell[i][j];
            }
        }
        memset(dis,0,sizeof(dis));
        // for(int i = 0;i<h;i++){
        //     for(int j = 0;j<w;j++){
        //         cout<<cell[i][j];
        //     }cout<<endl;
        // }
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(cell[i][j]=='A'&&dis[i][j]==0){
                    dfs(i,j,0);
                }
            }
        }
        int ans = -1000;
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                ans = max(ans,dis[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}