#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
int board[100][100];
int dx1[4] = {-1, 0, 1, 0};
int dx2[4] = {1, 0, -1, 0};

int dy[4] = {0, 1, 0, -1};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, t; cin >> r >> c >> t;

    vector<pair<int, int>> cleaners;
    for(int i =0; i < r; i++)
        for(int j =0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == -1) {
                cleaners.push_back({i, j});
            }
        }

    while(t--){
        int temp[100][100];
        fill(&temp[0][0], &temp[99][100], 0);

        // 미세먼지가 확산된다.
        // ! 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] != 0){
                    int cnt = 0;    // 확산된 방향의 개수
                    for(int dir = 0; dir < 4; dir++){
                        int nx = i + dx1[dir];
                        int ny = j + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                        if(board[nx][ny] == -1) continue;

                        cnt++;
                        temp[nx][ny] += board[i][j] / 5;
                    }

                    temp[i][j] += board[i][j] - ((board[i][j]/5) * cnt);
                }
            }
        }

        memcpy(board, temp, sizeof(board));

        // 공기청정기가 작동한다.
        // 위쪽 공기청정기 바람 -> 아래쪽 공기청정기 바람 순으로 진행
        // 위쪽 바람 : 위, 오른쪽, 아래, 왼쪽
        // 아래쪽 바람 : 아래, 오른쪽, 위쪽, 왼쪽
        for(int i = 0; i < cleaners.size(); i++){
            int * dx;
            if(i == 0) dx = dx1; else dx = dx2;

            int dir = 0;
            // ! 공기 청정기에서 한 칸 움직인 곳에서 시작
            pair<int, int> cur = {cleaners[i].x + dx[dir], cleaners[i].y};
            pair<int, int> nxt = {-1, -1};
            int cnt = 0;
            while(true){
                if(cur.x == r - 1 && cur.y == 0 || cur.x == r - 1 && cur.y == c - 1 || cur.x == cleaners[i].x && cur.y == c - 1
                   || cur.x == 0 && cur.y == 0 || cur.x == 0 && cur.y == c - 1 || cur.x == cleaners[i].x && cur.y == c - 1) dir++;

                nxt.x = cur.x + dx[dir];
                nxt.y = cur.y + dy[dir];
                if(nxt.x == cleaners[i].x && nxt.y == cleaners[i].y) break;
                // nx에서 cur로 바람 이동
                board[cur.x][cur.y] = board[nxt.x][nxt.y];
                cur = nxt;
            }
            board[cur.x][cur.y] = 0;
        }
    }

    int sum = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(board[i][j] != -1) sum += board[i][j];

    cout << sum << "\n";
}

/*
7 8 1
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 13 10 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

*/