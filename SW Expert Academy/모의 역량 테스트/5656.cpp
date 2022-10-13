// Created by 길민호 on 2022/10/14.

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int board[20][20];
bool vis[20][20];

int n, w, h;
int ans = INT_MAX;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void breakBrick(int x, int y, int board[20][20], vector<pair<int, int>>& bricks){
    bricks.push_back({x, y});
    int dist = board[x][y];

    vis[x][y] = true;

    for(int dir = 0; dir < 4; dir++){
        for(int d = 1; d < dist; d++){
            int nx = x + (dx[dir] * d);
            int ny = y + (dy[dir] * d);

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(vis[nx][ny]) continue;
            breakBrick(nx, ny, board, bricks);
        }
    }
}

void brickDown(int board[20][20]){
    for(int y = 0; y < w; y++){
        for(int x = h - 1; x >= 0; x--){
            if(board[x][y] == 0){
                int nx = x;
                while(board[nx][y] == 0){
                    nx--;
                    if(nx < 0) break;
                }
                if(nx < 0) break;
                else {
                    board[x][y] = board[nx][y];
                    board[nx][y] = 0;
                }
            }
        }
    }
}

void brickBreaker(int th, int board[20][20], int remainBrickCnt){
    ans = min(ans, remainBrickCnt);
    if(th < n){
        for(int j = 0; j < w; j++){
            for(int i = 0; i < h; i++){
                if(board[i][j] == 0) continue;

                // board[i][j]를 부심
                int tempBoard[20][20];
                memcpy(tempBoard, board, sizeof (tempBoard));

                vector<pair<int, int>> bricks;
                fill(&vis[0][0], &vis[19][20], 0);
                breakBrick(i, j, tempBoard, bricks);

                int tempRemainBrickCnt = remainBrickCnt;
                for(auto breaked : bricks){
                    if(tempBoard[breaked.x][breaked.y] != 0){
                        tempRemainBrickCnt--;
                        tempBoard[breaked.x][breaked.y] = 0;
                    }
                }

                brickDown(tempBoard);
                brickBreaker(th + 1, tempBoard, tempRemainBrickCnt);
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n >> w >> h;
        ans = INT_MAX;

        int brickCnt = 0;
        for(int i = 0; i < h; i++)
            for(int j= 0; j < w; j++){
                cin >> board[i][j];
                if(board[i][j] != 0) brickCnt++;
            }
        brickBreaker(0, board, brickCnt);

        // cout << "remain : " << brickCnt << "\n";
        cout << "#" << tc << " " << ans << "\n";
    }
}

/*

1
3 10 10
0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0
1 0 3 0 1 1 0 0 0 1
1 1 1 0 1 2 0 0 0 9
1 1 4 0 1 1 0 0 1 1
1 1 4 1 1 1 2 1 1 1
1 1 5 1 1 1 1 2 1 1
1 1 6 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 5
1 1 7 1 1 1 1 1 1 1

1
2 9 10
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
1 1 0 0 1 0 0 0 0
1 1 0 1 1 1 0 1 0
1 1 0 1 1 1 0 1 0
1 1 1 1 1 1 1 1 0
1 1 3 1 6 1 1 1 1
1 1 1 1 1 1 1 1 1
*/