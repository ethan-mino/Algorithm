// Created by 길민호 on 2022/07/02.

#include <bits/stdc++.h>
using namespace std;

#define CASE 10
#define SIZE 16
#define x first
#define y second

int board[SIZE][SIZE];
int vis[SIZE][SIZE];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cur = 0;
    while(cur < CASE){
        int t; cin >> t;
        fill(&board[0][0], &board[SIZE - 1][SIZE], 0);
        fill(&vis[0][0], &vis[SIZE - 1][SIZE], 0);

        pair<int, int> st, en;
        for(int i = 0; i < SIZE; i++){
            string str; cin >> str;
            for(int j = 0; j < str.size(); j++){
                board[i][j] = str[j] - 48;
                if(board[i][j] == 2) st = {i, j};
                if(board[i][j] == 3) en = {i, j};
            }
        }

        queue<pair<int, int>> q;
        q.push(st);
        vis[st.x][st.y] = 1;

        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE) continue;
                if(board[nx][ny] == 1 || vis[nx][ny] != 0) continue;
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }

        cout << "#" << t << " ";
        if(vis[en.x][en.y] == 0) cout << 0;
        else cout << 1;
        cout << "\n";
        cur++;
    }
}

