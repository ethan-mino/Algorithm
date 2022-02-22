#include <bits/stdc++.h>
using namespace std;

int dx[6] = {-1, 0, 0, 1, 0, 0};
int dy[6] = {0, -1, 0, 0, 1, 0};
int dz[6] = {0, 0, -1, 0, 0, 1};

typedef struct{
    int x, y, z;
}pos;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int ans = 0;

        int l, r, c;
        cin >> l >> r >> c;

        if(!l && !r && !c)
            break;
        else{
            queue<pos> q;
            pos end;
            char board[30][30][30] = {};
            int vis[30][30][30] = {};

            for(int i = 0; i < l; i++)
                for(int j = 0; j < r; j++)
                    for(int k = 0; k < c; k++){
                        cin >> board[j][k][i];
                        if(board[j][k][i] == 'S'){
                            vis[j][k][i] = 1;
                            q.push({j, k, i});
                        }else if(board[j][k][i] == 'E'){
                            end = {j, k, i};
                        }
                    }

            while(!q.empty()){
                pos cur = q.front(); q.pop();

                for(int dir = 0; dir < 6; dir++){
                   int nx = cur.x + dx[dir];
                   int ny = cur.y + dy[dir];
                   int nz = cur.z + dz[dir];

                   if(nx < 0 || ny < 0 || nz < 0 || nx >= r || ny >= c || nz >= l) continue;
                   if(board[nx][ny][nz] == '#' || vis[nx][ny][nz] != 0) continue;
                   
                   vis[nx][ny][nz] = vis[cur.x][cur.y][cur.z] + 1;

                   q.push({nx, ny, nz});
                }

                if(vis[end.x][end.y][end.z] != 0)
                    break;
            }

            ans = vis[end.x][end.y][end.z];
            if(ans != 0) cout << "Escaped in "<< ans - 1 << " minute(s)." << "\n";
            else cout << "Trapped!" << "\n";
        }
    }
}