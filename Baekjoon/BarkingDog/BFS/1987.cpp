// Created by SSAFY on 2022-08-17.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

char board[30][30];
int dist[30][30];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool sel[30];
int r, c;
int ans = 0;

void dfs(int cnt, pair<int, int> cur){
    ans = max(ans, cnt);

    for(int dir = 0; dir < 4; dir++){
        int nx = cur.x + dx[dir];
        int ny = cur.y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;

        if(!sel[board[nx][ny] - 'A']){
            sel[board[nx][ny] - 'A'] = true;
            dfs(cnt + 1, {nx, ny});
            sel[board[nx][ny] - 'A'] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> board[i][j];

    sel[board[0][0] - 'A'] = true;
    dfs(1, {0, 0});

    cout << ans << "\n";
}

/*
2 4
A A A A
A A A A
*/