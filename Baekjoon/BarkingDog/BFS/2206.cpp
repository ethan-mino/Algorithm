#include <bits/stdc++.h>
using namespace std;

#define x first 
#define y second

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int board[1000][1000];
int vis[1000][1000][2];

int bfs(pair<int, int> s, int s_vis, int n, int m, int wall){ // 깰 수 있는 벽의 개수가 wall일 때, s부터 (N, M)까지의 최단거리를 구하는 함수
    queue<pair<int, int> > q;

    q.push(s);
    vis[s.x][s.y][wall] = s_vis;
    int ans = 0;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){   //   상,하,좌,우를 확인하고, 길이면서 방문하지 않은 길을 push
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            if((wall == 1 && board[nx][ny] == 1)  // 벽이고, 깰 수 있는 벽이 있는 경우
            && ((nx >= 1 && nx < n - 1 && board[nx - 1][ny] == 0 && board[nx + 1][ny] == 0)
            || (ny >= 1 && ny < m - 1 && board[nx][ny - 1] == 0 && board[nx][ny + 1] == 0))){ // 벽이면서, 벽의 상하 또는 좌우가 벽이 아닌 경우, 해당 벽을 길로 만들고 탐색
                if(vis[nx][ny][0] == 0 // 아직 방문하지 않았거나 
                || (vis[cur.x][cur.y][1] + 1 < vis[nx][ny][0] && vis[cur.x][cur.y][1] + 1 < vis[nx][ny][0])){ // 벽을 깼을 때, 깨지 않았을 때 보다 {nx, ny}에 더 빠르게 도착하는 경우
                    board[nx][ny] = 0;
                    bfs({nx, ny}, vis[cur.x][cur.y][wall] + 1, n, m, 0);    // 깰 수 있는 벽의 수를 0으로 만들고 해당 벽부터 탐색
                    board[nx][ny] = 1;  // 벽 복원
                }
            }

            if(board[nx][ny] == 1) continue;

            // 아직 방문하지 않았거나, wall이 같을 때 기존의 최단 거리보다 더 빠르게 도착할 수 있는 경우 탐색 진행
            if(vis[nx][ny][wall] == 0 || vis[cur.x][cur.y][wall] + 1 < vis[nx][ny][wall]){  
                vis[nx][ny][wall] = wall;
                vis[nx][ny][wall] = vis[cur.x][cur.y][wall] + 1;
                q.push({nx, ny});
            }

        }
    }

    if(vis[n - 1][m - 1][0] == 0) ans = vis[n - 1][m - 1][1];  // 벽을 깬 경우 보다 벽을 깨지 않은 경우가 더 빨리 도착하는 경우
    else ans = vis[n - 1][m - 1][0];    // 벽을 깬 경우가 더 빨리 도착하는 경우

    if(ans == 0) return -1; // 벽을 깼을 때, 깨지 않았을 때 모두 도착 지점에 도달할 수 없는 경우
    else return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    for(int i = 0; i < n; i++){
        string str; cin >> str;

        for(int j = 0; j < m; j++)
            board[i][j] = str[j] - 48;
    }
    
    cout << bfs({0, 0}, 1, n, m, 1) << "\n";
}

/*
6 4
0000
1110
1000
0000
0111
0000

6 4
0100
1110
0000
0000
0111
0000

6 4
0100
0110
0000
0000
1111
0000

6 4
0100
0110
0000
0000
0111
0000


6 4
0100
1110
0000
0000
1101
0000

6 4
0100
0110
0000
0010
1101
0000

6 4
0111
0111
0000
0010
1101
0000

6 4 
0000
0000
0000
0000
0000
0000


6 4
0111
0111
0000
0000
1111
0000


6 11
00000000011
01111111111
00001111111
00000000000
11111010101
00000000010

7 11
00000000010
01111111110
01000111110
00010000000
11111111110
11111111111
00000000000
*/