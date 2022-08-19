#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

typedef struct {
    char c;
    int dist;
}elem;

char board[1000][1000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int w, h;
        cin >> w >> h;

        fill(&board[0][0], &board[999][1000], 0);

        queue<pair<int, int>> q; // 상근이 Bfs 배열
        pair<int, int> pos; // 상근이 위치
        elem vis[1000][1000];

        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++){
                cin >> board[i][j];
                if(board[i][j] == '*'){
                    q.push({i, j});
                    vis[i][j] = {'*', 1};
                }else{
                    vis[i][j] = {'#', 0};
                }
            }

        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++){
                if(board[i][j] == '@'){
                    q.push({i, j});
                    vis[i][j] = {'@', 1};
                    pos = {i, j};
                }
            }
        
        board[pos.x][pos.y] = '.';

        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();    

            for(int dir = 0; dir < 4; dir++){   // 불이 붙으려는 칸에 상근이가 이동할 수 없기 때문에 불이 먼저 이동
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if(board[nx][ny] == '#' || vis[nx][ny].dist != 0) continue;
                vis[nx][ny].c = vis[cur.x][cur.y].c;
                vis[nx][ny].dist = vis[cur.x][cur.y].dist + 1;
                q.push({nx, ny});
            }
        }     

        int ans = 1000001;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(i == 0 || j == 0 || i == h - 1 || j == w - 1){
                    if(vis[i][j].c == '@')
                        ans = min(ans, vis[i][j].dist);
                }
            }
        }

        if(ans == 1000001) cout << "IMPOSSIBLE" << "\n";
        else cout << ans << "\n";
    }
}