// Created by SSAFY on 2022-08-03.

#include <bits/stdc++.h>
using namespace std;

#define num first
#define pos second
#define dir second
#define x first
#define y second
#define SIZE 4
typedef pair<int, pair<int, int>> pii;
typedef pair<int, int> pi;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int ans = 0;

void swap(pair<int, int> a[SIZE][SIZE], pi p1, pi p2){
    // {x1, y1}, {x2, y2}를 swap
    pair<int, int> temp = a[p1.x][p1.y];
    a[p1.x][p1.y] = a[p2.x][p2.y];
    a[p2.x][p2.y] = temp;
}

void back(pair<int, int> board[SIZE][SIZE], int sum){
    cout << sum << "\n";
//    for(int i = 0; i < SIZE; i++){
//        for(int j = 0; j < SIZE; j++){
//            cout << "(" << board[i][j].num << " " << board[i][j].dir << ") ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

    // 각 물고기의 위치와 방향, 물고기의 이동 순서가 주어졌을 때,
    // 상어가 먹을 수 있는 물고기 번호의 합을 반환하는 함수

    int pre = 0;
    while(true){
        pii cur = {INT_MAX, {-1, -1}};
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                if(board[i][j].num > pre && board[i][j].num < cur.num)
                    cur = {board[i][j].num, {i, j}};
            }
        }

        if(cur.num == INT_MAX) break;

        pre = cur.num;
        //cout << cur.num << "\n";
        int dir = board[cur.pos.x][cur.pos.y].dir;

        if(cur.num == 17){   // 현재 순서가 상어인 경우
            bool move = false;
            // 한 번에 여러 개의 칸을 이동할 수 있다.
            // 이동하는 중에 지나가는 칸에 있는 물고기는 먹지 않는다.
            int i = 1;

            while(true){
                int nx = cur.pos.x + dx[dir] * i;
                int ny = cur.pos.y + dy[dir] * i;
                i++;
                //cout << nx << " " << ny << "\n";
                if(nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE) break;  // 공간의 경계를 넘는 경우, d
                if(board[nx][ny].num == -1) continue; //  해당 칸에 물고기가 없는 경우

                pair<int, int> temp[SIZE][SIZE];
                memcpy(temp, board, sizeof(temp));

                // 상어가 물고기가 있는 칸으로 이동했다면, 그 칸에 있는 물고기를 먹고, 그 물고기의 방향을 가지게 된다.
                move = true;
                int ts = sum + temp[nx][ny].num;
                temp[nx][ny].num = 17;  // 상어 이동
                temp[cur.pos.x][cur.pos.y] = {-1, -1};    // 기존에 있던 공간은 -1로 표시
                back(temp, ts);
            }

            if(!move) ans = max(ans, sum); // 상어가 더이상 이동할 수 있는 칸이 없는 경우
            break;
        }else{  // 물고기인 경우
            bool move = false;
            int nx, ny;
            int tDir = dir;
            //cout << "dir : " << dir << "\n";
            while(true){ // 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전
                nx = cur.pos.x + dx[tDir];
                ny = cur.pos.y + dy[tDir];
                //cout << nx << " " << ny << "\n";
                if(nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE // 공간의 경계를 넘는 경우
                || board[nx][ny].num == 0){   // 상어가 있거나
                    tDir = (tDir + 1) % 8;    // 45도 반시계 회전시킨다.
                }else{  // 움직일 수 있는 칸이 있다면
                    move = true;
                    break;
                }

                // 한바퀴 다 돈 경우
                if(tDir == dir) break;
            }

            board[cur.pos.x][cur.pos.y].dir = tDir;
            if(move){   // 물고기가 움직일 수 있는 칸이 있다면
                if(board[nx][ny].num == -1){    // 이동하려는 칸에 물고기가 없는 경우
                    board[nx][ny] = board[cur.pos.x][cur.pos.y];    // 다음 위치로 이동
                    board[cur.pos.x][cur.pos.y] = {-1, -1}; // 원래 위치에 물고기가 없음을 표시
                }else{  // 물고기가 있는 경우
                    // 해당 칸에 있는 물고기와 위치를 바꿈
                    swap(board, cur.pos, {nx, ny});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 각 좌표에 있는 물고기의 {번호, 방향}을 저장하는 2차월 배열
    pair<int, int> b[SIZE][SIZE];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> b[i][j].num >> b[i][j].dir;
            b[i][j].dir--;  // dir의 값이 0 ~ 7이 되도록 -1
        }
    }

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << "(" << b[i][j].num << " " << b[i][j].dir << ") ";
        }
        cout << "\n";
    }
    cout << "\n";

    pair<int, int> st = {0, 0}; // 상어의 시작 위치

    ans += b[st.x][st.y].num; // {0, 0} 위치의 물고기 번호를 더해줌
    b[st.x][st.y].num = 17;    // {0, 0} 위치를 상어로 표시 (num이 17이면 상어)

    back(b, ans);
    cout << ans << "\n";
}
/*
7 1 2 3 15 6 9 8
3 1 1 8 14 7 10 1
6 1 13 6 4 3 11 4
16 1 8 7 5 2 12 2

7 6 2 3 15 6 9 8
3 1 1 8 14 7 10 1
6 1 13 6 4 3 11 4
16 1 8 7 5 2 12 6

7 7 2 7 15 7 9 7
-1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1
-> 33

7 7 2 7 15 7 9 5
-1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1

1 6 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 5 7
*/

// 1 7 10 12 15