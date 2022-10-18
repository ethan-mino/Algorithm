// Created by SSAFY on 2022-10-18.

#include <bits/stdc++.h>
using namespace std;

#define MAX_MOVE 5
#define x first
#define y second

int board[20][20];

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ddx[2] = {0, 1};
int ddy[2] = {1, 0};

int n;

struct Block{
    int x, y, size;
};

int maxBlock = INT_MIN;
void move(pair<int, int> st, int dir, int board[20][20]){
    int oppositeDir = (dir % 2 == 0) ? dir + 1 : dir - 1;   // 작용하는 동작의 반대 방향
    deque<Block> blocks;

    // 반대 방향으로 가면서 블록을 empty 큐에 넣음
    for(int th = 0; th < n; th++){
        int nx = st.x + dx[oppositeDir] * th;
        int ny = st.y + dy[oppositeDir] * th;

        if(board[nx][ny] != 0) {
            blocks.push_back({nx, ny, board[nx][ny]});
            board[nx][ny] = 0;
        }
    }

    // 반대 방향으로 가면서 빈 곳에 합친 블록을 넣어줌
    for(int th = 0; th < n; th++){
        int nx = st.x + dx[oppositeDir] * th;
        int ny = st.y + dy[oppositeDir] * th;

        if(blocks.empty()) break;

        Block frontBlock = blocks.front(); blocks.pop_front();
        int frontBlockSize = frontBlock.size;

        if(blocks.size() >= 1){   // 2개 이상의 블록이 남아있는 경우
            Block secondBlock = blocks.front();
            int secondBlockSize = secondBlock.size;

            if(frontBlockSize == secondBlockSize){
                blocks.pop_front();
                board[nx][ny] = frontBlockSize * 2;
            }else{
                board[nx][ny] = frontBlockSize;
            }
        }else{  // 하나의 블럭만 있는 경우
            board[nx][ny] = frontBlockSize;
        }
    }
}

void moveBoard(int dir, int board[20][20]){
    pair<int, int> st[4] = {{0, 0}, {n - 1, 0}, {0, 0}, {0, n - 1}};
    pair<int, int> stPos = st[dir];

    // dir이 상인 경우, 즉 위로 작용하는 경우, 시작 지점은 (0, 0), (0, 1) ... 오른쪽으로 이동
    // dir이 하인 경우, 즉 아래로 작용하는 경우, 시작 시점은 (n - 1, 0), (n - 1, 1) ... 오른쪽으로 이동
    // dir이 좌인 경우, 즉, 왼쪽으로 작용하는 경우, 시작 지점은 (0, 0), (1, 0) ... 아래쪽으로 이동
    // dir이 우인 경우, 즉, 오른쪽으로 작용하는 경우, 시작 지점은 (0, n - 1), (1, n - 1)... 아래쪽으로 이동
    for(int cnt =0 ; cnt < n; cnt++){
        int ddir = (dir <= 1) ? 0 : 1;
        int nx = stPos.x + ddx[ddir] * cnt;
        int ny = stPos.y + ddy[ddir] * cnt;

        move({nx, ny}, dir, board);
    }
}

void game(int th, int board[20][20]){
    if(th == MAX_MOVE){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] > maxBlock)
                    maxBlock = board[i][j];

    }else{
        for(int dir = 0; dir < 4; dir++){
            int tempBoard[20][20];
            memcpy(tempBoard, board, sizeof(tempBoard));
            moveBoard(dir, tempBoard);
            game(th + 1, tempBoard);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

     game(0, board);
     cout << maxBlock << "\n";
}