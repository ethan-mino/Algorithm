<<<<<<< HEAD:Baekjoon/BarkingDog/simulation/20058.cpp
// Created by SSAFY on 2022-08-09.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[70][70], temp[70][70];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, q;

// 남아있는 얼음의 합과 가장 큰 덩어리가 차지하는 칸의 개수를 반환하는 함수
// 단순 BFS 사용, 영역 구하기 문제와 동일
pair<int, int> area(){
    int m = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 0){
                sum += board[i][j];
                queue<pair<int, int>> q;
                int vis[70][70];
                fill(&vis[0][0], &vis[69][70], 0);
                int cnt = 1;

                q.push({i, j});
                vis[i][j] = 1;
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] != 0) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                        cnt++;
                    }
                }
                m = max(m, cnt);
            }
        }
    }
    if(m == INT_MIN) m = 0;
    return {sum, m};
}
/*
3 1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
1

3 1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
2
*/