// Created by SSAFY on 2022-08-19.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define r first
#define c second
int board[30][30];

pair<int, int> move(int dir, int row, int col){
    if(dir == 0){   // 상
        int tmp = (col % 1000);
        col = (col % 10) * 1000 + (col / 10);
        row = (row / 100) * 100 + (col / 100) % 10 * 10 + (row % 10);
    }else if(dir == 1){ // 우
        int tmp = col % 10;
        col = (col / 1000) * 1000 + (row % 10) * 100 + ((col % 100) / 10) * 10 + row / 100;
        row = (row % 100) * 10 + tmp;
    }else if(dir == 2){ // 하
        int tmp = col / 1000;
        col = (col % 1000) * 10 + tmp;
        row = (row / 100) * 100 + (col / 100) % 10 * 10 + (row % 10);
    }else{  // 좌
        int tmp = col % 10;
        col = (col / 1000) * 1000 + (row / 100) * 100 + ((col % 100) / 10) * 10 + row % 10;
        row = (tmp) * 100 + row / 10;
    }
    return {row, col};
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k;

int bfs(pair<int, int> st){
    int vis[30][30];
    fill(&vis[0][0], &vis[29][30], 0);
    queue<pair<int, int>> q;

    q.push(st);
    vis[st.x][st.y] = 1;
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n; ny >= m) continue;
            if(vis[nx][ny] != 0 || board[nx][ny] != board[st.x][st.y]) continue;
            q.push({nx, ny});
            vis[nx][ny] = vis[cur.x][cur.y] + 1;
        }
    }

    int dist = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(vis[i][j]) dist++;
    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int ans = 0;
    int row = 463, col = 2651;
    int dir = 1;
    pair<int, int> cur = {0, 0};

    while(k--){
        int nx = cur.x + dx[dir];
        int ny = cur.y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            dir = (dir + 2) % 4;
            k++;
            continue;
        }
        tie(row, col) = move(dir, row, col);

        int bottom = row / 10 % 10;
        if(bottom < board[nx][ny]){
            dir--; if(dir == -1) dir = 3;
        }else if(bottom > board[nx][ny]){
            dir = (dir + 1) % 4;
        }
        ans += board[nx][ny] * bfs({nx, ny});
        cur = {nx, ny};
    }
    cout << ans << "\n";
}

/*
col : 2156
row : 413

  2
4 1 3
  5
  6

col : 4136
row : 512
  시계
  4
5 1 2
  3
  6

col : 4136
row : 215

  반시계
  4
2 1 5
  3
  6
*/