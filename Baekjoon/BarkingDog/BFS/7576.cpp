#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[1000][1000];
int vis[1000][1000];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)  {
            cin >> board[i][j];
            if(board[i][j] == 1){   // 익은 토마토의 경우
                q.push({i, j});    // 익은 토마토들의 위치를 push
                vis[i][j] = 1;  // 해당 위치 방문 표시
            }            
        }
    }

    int ans = 0;

    while(!q.empty()){ // 큐가 비지 않을 때까지 반복
        pair<int, int> cur = q.front(); q.pop();  // 큐에서 방문할 위치를 pop

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] != 0 || vis[nx][ny] != 0) continue;    // 이미 방문했거나 익지 않은 토마토가 아닌 경우, 방문하지 않음

            vis[nx][ny] = vis[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
        
        ans = max(ans, vis[cur.x][cur.y] - 1);   // 처음에 1로 시작하므로 -1 해줌
    }
    
    bool flag = true;

    for(int i = 0; i < n; i++) // 익지 않은 토마토 중에 방문하지 않은 토마토가 있는 지 확인
        for(int j = 0; j < m; j++)
            if(vis[i][j] == 0 && board[i][j] != -1)
                flag = false;

    if(flag) cout << ans;   
    else cout << -1;    // 익지 않은 토마토 중에 방문하지 않은 토마토가 있다면 -1 출력
}

