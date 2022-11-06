// Created by SSAFY on 2022-10-21.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[510][510];
int dp[510][510];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

// -1은 갈 수 없다, 0은 아직 탐색하지 않음을 의미
int back(pair<int, int> cur){
    if(cur.x == 0 && cur.y == 0) return 1;

    int & ref = dp[cur.x][cur.y];
    if(ref != -1) return ref;
    else{
        ref = 0;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[cur.x][cur.y] >= board[nx][ny]) continue;

            ref += back({nx, ny});
        }
        return ref;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    fill(&dp[0][0], &dp[499][500], -1);
    cout << back({n - 1, m - 1});
}