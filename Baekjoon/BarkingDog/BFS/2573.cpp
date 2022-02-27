#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[300][300];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    int ans = 0;

    while(true){
        int vis[300][300] = {};
        int sea[300][300] = {};
        int area = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] != 0 && vis[i][j] == 0){ // 덩어리의 개수 구함
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    area++;
                    
                    while(!q.empty()){
                        pair<int, int> cur = q.front(); q.pop();

                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.x + dx[dir];
                            int ny = cur.y + dy[dir];                   

                            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if(board[nx][ny] == 0) sea[cur.x][cur.y]++;
                            if(board[nx][ny] == 0 || vis[nx][ny] != 0) continue;
        
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }

        if(area >= 2 || area == 0) {
            if(area == 0) ans = 0;
            break;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board[i][j] = (board[i][j] > sea[i][j]) ? board[i][j] - sea[i][j] : 0;

        ans++;
    }

    cout << ans << "\n";
}