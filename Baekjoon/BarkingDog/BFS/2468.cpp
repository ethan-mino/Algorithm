#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[100][100];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int m = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            m = max(m, board[i][j]);
        }
    }

    int ans = 0;

    for(int floor = 0; floor < m; floor++){
        for(int i = 0; i < n; i++){
            for(int j = 0;  j < n; j++){
                if(floor >= board[i][j])
                    board[i][j] = 0;    // 잠긴 지역은 0으로 표시
            }
        }

        int vis[100][100] = {};
        int cnt = 0;    // cnt++;  잠기지 않은 영역의 개수

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                if(board[i][j] != 0 && vis[i][j] == 0){ // 방문하지 않았고, 잠기지 않은 경우
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    cnt++;

                    while(!q.empty()){
                        pair<int, int> cur = q.front(); q.pop();

                       for(int dir = 0; dir < 4; dir++){
                            int nx = cur.x + dx[dir];
                            int ny = cur.y + dy[dir];

                            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                            if(board[nx][ny] == 0 || vis[nx][ny] != 0) continue;  // 잠긴 지역이거나 이미 방문한 경우

                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }

        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}
