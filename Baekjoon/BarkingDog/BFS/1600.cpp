#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[200][200];
int vis[200][200][31];

int dx1[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
int dy1[8] = {-1, -2, 1, 2, -1, -2, 1, 2};

int dx2[4] = {-1, 0, 1, 0};
int dy2[4] = {0, -1, 0, 1};

int k, n, m;

void bfs(pair<int, int> s, int v, int num){
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.x][s.y][num] = v;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        int n_vis = vis[cur.x][cur.y][num] + 1;

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx2[dir];
            int ny = cur.y + dy2[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == 1 || (vis[nx][ny][num] != 0 &&n_vis >= vis[nx][ny][num])) continue;
            q.push({nx, ny});
            vis[nx][ny][num] = n_vis;
        }

        if(num > 0){
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.x + dx1[dir];
                int ny = cur.y + dy1[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if(board[nx][ny] == 0 
                && (vis[nx][ny][num - 1] == 0 || vis[nx][ny][num - 1] > n_vis)){
                    bfs({nx, ny}, n_vis, num - 1);
                }
            } 
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> m >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    bfs({0, 0}, 1, k);

    int ans = 50000;
    for(int i = 0; i <= k; i++)
        if(vis[n - 1][m - 1][i] != 0 && vis[n - 1][m - 1][i] < ans)
            ans = vis[n - 1][m - 1][i];
    
    if(ans == 50000) cout << -1;
    else cout << ans - 1;
}

/*
2
4 4
0 0 0 0
1 0 0 0
0 0 1 0
0 1 0 0

3
8 7
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

3
5 5
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
*/