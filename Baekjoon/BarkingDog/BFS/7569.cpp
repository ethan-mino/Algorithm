#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int x, y, z;
}pos;

int board[100][100][100];
int vis[100][100][100];

int dx[6] = {-1, 0, 0, 1, 0, 0};
int dy[6] = {0, -1, 0, 0, 1, 0};
int dz[6] = {0, 0, -1, 0, 0, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z;
    cin >> y >> x >> z;

    queue<pos> q;

    for(int k = 0; k < z; k++)
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1){
                    q.push({i, j, k});  // 익은 토마토의 위치 모두 push
                    vis[i][j][k] = 1;   // 익은 토마토의 위치 방문 표시
                }
            }

    int ans = 0;

    while(!q.empty()){
        pos cur = q.front(); q.pop();

        for(int dir = 0; dir < 6; dir ++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            int nz = cur.z + dz[dir];

            if(nx < 0 || ny < 0 || nz < 0 || nx >= x || ny >= y || nz >= z) continue;
            
            if(board[nx][ny][nz] != 0 || vis[nx][ny][nz] != 0) continue;    // 익지 않은 토마토가 아니거나, 이미 방문했다면 건너뜀
            pos np = {nx, ny, nz};
            q.push(np);

            vis[nx][ny][nz] = vis[cur.x][cur.y][cur.z] + 1;
            ans = max(ans, vis[cur.x][cur.y][cur.z]);
        }
    }

    bool flag = true;        
    
    for(int k = 0; k < z; k++)
        for(int i = 0; i < x; i++)
             for(int j = 0; j < y; j++)
                if(board[i][j][k] == 0 && vis[i][j][k] == 0)
                    flag = false;

    if(flag) cout << ans;
    else cout << -1;
}