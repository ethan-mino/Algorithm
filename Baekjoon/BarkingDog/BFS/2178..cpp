#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[103][103];
int vis[103][103];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        for(int j = 0; j < m; j++){
            board[i][j] = s[j] - 48;
        }
    }

    queue<pair<int, int> > q;
    vis[0][0] = 1;
    q.push({0, 0});

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == 0 || vis[nx][ny] != 0) continue;

            vis[nx][ny] = vis[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }

        if(cur.x == n - 1 && cur.y == m - 1)
            cout << vis[cur.x][cur.y];
    }
}