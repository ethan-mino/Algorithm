#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char board[1000][1000];
int vis1[1000][1000];   // 지훈이의 방문 표시 배열
int vis2[1000][1000];   // 불의 방문 표시 배열

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void BFS(queue<pair<int, int> > q, int vis[][1000], int n, int m){
    while(!q.empty()){
        pair<int, int> cur = q.front();q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny] != 0 || board[nx][ny] != '.') continue;

            vis[nx][ny] = vis[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int> > u;        
    queue<pair<int, int>> f;        
    pair<int, int> ul;

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'J') {
                u.push({i, j});
                ul = {i, j};
                vis1[i][j] = 1;
            } else if(board[i][j] == 'F'){
                f.push({i, j});
                vis2[i][j] = 1;
            } 
        }
    }

    BFS(u, vis1, n, m);
    board[ul.x][ul.y] = '.';

    BFS(f, vis2, n, m);
    
    int ans = 10000000;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if(vis1[i][j] != 0 && vis1[i][j] < vis2[i][j]   // 지훈이와 불 모두 접근 가능하지만, 지훈이가 더 빠른 경우
                || vis2[i][j] == 0 && vis1[i][j] > vis2[i][j])  // 지훈이는 접근 가능하지만, 불은 접근 불가능한 경우
                    ans = min(ans, vis1[i][j]);
            }
        }
    }
   
    if(ans == 10000000) cout << "IMPOSSIBLE";
    else cout << ans;
}