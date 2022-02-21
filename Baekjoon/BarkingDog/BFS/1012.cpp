#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;

    while(c--){
        int board[50][50] = {};  // 탐색 대상 배열
        int vis[50][50] = {};    // 방문 표시 배열

        int n, m, cnt, ans = 0;
        cin >> n >> m >> cnt;

        for(int i = 0; i < cnt; i++){
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 1 && vis[i][j] == 0){  // 배추가 심어져 있지만, 아직 방문하지 않은 경우
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;

                    while(!q.empty()){
                        pair<int, int> cur = q.front(); q.pop();

                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.x + dx[dir];
                            int ny = cur.y + dy[dir];

                            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if(board[nx][ny] != 1 || vis[nx][ny] != 0) continue;
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}