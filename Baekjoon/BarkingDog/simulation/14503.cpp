#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int x, y, dir;
}state;

int board[50][50];
int vis[50][50];

int dx[4] = {0, 1, 0, -1};  // 서, 남, 동, 북 
int dy[4] = {-1, 0, 1, 0};  // 서, 남, 동, 북 

int n, m, r, c, d;
int ans = 0;

void clean(state cur){    // 0 : 서, 1 : 남, 2 : 동, 3 : 북
    vis[cur.x][cur.y] = 1;  // 시작점을 청소한다
    
    while (true){
        bool clean = false; // 현재 위치에서 인접한 칸을 청소했음을 나타내는 flag
        // 현재 위치의 방향 (for문에서 탈출 조건으로 dir을 사용하므로, 반복에 영향을 주지 않도록 저장)
        int pre = cur.dir;  

        // 현재 방향의 왼쪽 방향부터 청소를 진행 (현재 방향이 0인 경우 1, 2, 3, 0 순서로 청소)
        for(int i=(pre+1)%4, th = 0; i!=(pre+1)%4 || th!=4; i = (i+1)%4, th++){
            int nx = cur.x + dx[i]; // 인접한 칸의 위치
            int ny = cur.y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 직사각형을 벗어나는 경우
            if(board[nx][ny] == 1 || vis[nx][ny] != 0) continue; // 이미 청소했거나, 벽인 경우
            
            ans++;
            clean = true;   // 인접한 칸을 청소했으므로 true로 표시
            vis[nx][ny] = 1; cur = {nx, ny, i};    // 인접한 칸을 청소 표시한 후, 해당 칸으로 이동
            break; // 다시 인접한 칸의 왼쪽 방향부터 청소하기 위해 break
        }

        if(!clean){ // 네 방향 모두 청소가 되어 있거나, 벽인 경우
            cur.x = cur.x + dx[(cur.dir + 2) % 4];  // 방향을 유지한 채, 후진
            cur.y = cur.y + dy[(cur.dir + 2) % 4];

            if(board[cur.x][cur.y] == 1)    // 후진한 방향이 벽인 경우 멈춤
                break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r >> c >> d;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    clean({r, c, 3 - d});
    cout << ans + 1;
}