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

// ! 핵심
// board의 일부를 rotate한 결과를 (0, 0)을 기준으로 temp에 저장한 다음 board에 저장
// ! 주의 n * n 크기의 temp에, board를 copy한 후,
// rotate 시킨 결과를 다시 board에 copy하는 경우 시간 초과 발생
void rotate(int r, int c, int len){ // 배열의 일부를 rotate 시키는 함수
    for(int x = r; x < r + len; x++){
        for(int y = c; y < c + len; y++){
            int x1 = x - r;
            int y1 = y - c;
            temp[y1][len - x1 - 1] = board[x][y];
        }
    }

    for(int x = 0; x < len; x++)
        for(int y = 0; y < len; y++)
            board[x + r][y + c] = temp[x][y];
}


// 1. 각 연산마다 부분 격자를 rotate 시킨다.
//  1-1 단, n * n 크기의 temp에, board를 copy한 후,
//      rotate 시킨 결과를 다시 board에 copy하는 경우 시간 초과 발생
//      따라서, board의 일부를 rotate한 결과를 (0, 0)을 기준으로 temp에 저장한 다음 board에 저장
// 2. 각 좌표를 확인하며 인접해있는 얼음 칸의 개수를 계산
//  2-1 주의, 빙산 문제와 유사하게, 얼음의 양이 줄어드는 것이 인접한 좌표에 영향을 주지 않도록 temp 배열을 사용
//  2-2 주의, 얼음이 -1로 떨어지면 0으로 설정하거나, 0이하의 값은 모두 얼음으로 취급해주어야 함

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    n = pow(2, n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)  // 얼음판 입력 받음
            cin >> board[i][j];

    for(int i = 0, s; i < q; i++){  // 각 연산을 수행
        cin >> s;
        int length = pow(2, s); // 각 부분 격자의 길이는 2^s

        for(int x = 0; x < n; x += length) // 각 격자를 rotate
            for(int y = 0; y < n; y += length)
                rotate(x, y, length);

        // 얼음이 있는 칸 3개 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어듦.
        // ! 주의 : 빙산 문제와 유사하게, 얼음의 양이 줄어드는 것이 인접한 좌표에 영향을 주지 않도록 temp 배열을 사용해야 함
        for(int x = 0; x < n; x++){     // 각 좌표를 확인하며 인접해있는 얼음 칸의 개수를 계산
            for(int y = 0; y < n; y++){
                int cnt = 0;
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(board[nx][ny] == 0) continue;    // 얼음이 아닌 경우 pass
                    cnt++;
                }

                temp[x][y] = board[x][y];   //
                if(cnt < 3) temp[x][y]--;
                // ! 주의 : 얼음이 -1로 떨어지면 0으로 설정하거나, 0이하의 값은 모두 얼음으로 취급해주어야 함
                if(temp[x][y] < 0) temp[x][y] = 0;
            }
        }
        memcpy(board, temp, sizeof(board)); // 업데이트 된 얼음의 양을 board에 copy
    }

    pair<int, int> ans = area();
    cout << ans.first << "\n" << ans.second << "\n";
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